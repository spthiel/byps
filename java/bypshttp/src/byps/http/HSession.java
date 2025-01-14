package byps.http;
import java.util.concurrent.atomic.AtomicReference;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import byps.BApiDescriptor;
import byps.BClient;
import byps.BHashMap;
import byps.BServer;
import byps.BTargetId;
import byps.BTransportFactory;
import jakarta.servlet.http.HttpSession;

/**
 * This class represents a session.
 * 
 * A HSession object is already created for negotiation, but it keeps alive only
 * for a short time {@link HConstants#MAX_INACTIVE_SECONDS_BEFORE_AUTHENTICATED} 
 * if the negotiate request does not contain a remote user attribute. If your session class
 * does not make use of authentication, call {@link #setSessionAuthenticated()} in the constructor.
 * Otherwise, call setSessionAuthenticated somewhere in your implementation.
 *
 */
public abstract class HSession 
//implements Serializable, don't know how to serialize this class. Don't know how to resolve the dependencies to other objects.
{

  protected final AtomicReference<HttpSession> httpSessRef = new AtomicReference<>();
  protected final HServerContext serverContext;
  protected final HWriteResponseHelper writeHelper;
  protected final HWireServer wireServer;
  protected final HWireClientR wireClientR;
  protected final String remoteUser;
  protected volatile long lastAccessTime;
  protected volatile int maxInactiveSeconds;

  protected final static int MAX_INACTIVE_SECONDS_NOT_AUTH = getOptionMaxInactiveSecondsAuth(); 
  
  /**
   * Construtor
   * @param httpSessionOrNull HTTP session object, can be null.
   * @param remoteUser Authenticated user, supplied from HttpSerlvetRequest.getRemoteUser(), can be null.
   * @param tempDir Temporary directory for storing streams, can be null.
   * @param serverRegistry Registry for BStub objects of all subscribers.
   * @param listener Listener for events triggered during processing.
   */
  public HSession(HttpSession httpSessionOrNull, String remoteUser, HServerContext serverContext) {
    if (log.isDebugEnabled())
      log.debug("HSession(");
    this.httpSessRef.set(httpSessionOrNull);
    this.serverContext = serverContext;
    this.remoteUser = remoteUser;

    writeHelper = new HWriteResponseHelper(serverContext.getListener());

    wireServer = new HWireServer(serverContext.getConfig(), serverContext.getActiveMessages(), writeHelper);

    wireClientR = new HWireClientR(wireServer);
    
    // Add this session object to the HttpSession object of the application server.
    // Set the inactive time to the maximum of all attached sessions.
    var hsess = httpSessRef.get();
    if (hsess != null) {
      HHttpSessionObject sessObj = (HHttpSessionObject)hsess.getAttribute(HConstants.HTTP_SESSION_BYPS_SESSIONS);
      if (sessObj == null) {
        sessObj = HSessionListener.initHttpSession(hsess); 
      }
      sessObj.addSession(this);
    }
    
    // Shorten the lifetime of the HTTP session, 
    // if there is no authenticated user.
    int inactiveSeconds = (remoteUser == null || remoteUser.length() == 0) ?
        MAX_INACTIVE_SECONDS_NOT_AUTH : HConstants.DEFAULT_INACTIVE_SECONDS_AUTHENTICATED;
    setMaxInactiveSeconds(inactiveSeconds);
    
    touch();
    
    if (log.isDebugEnabled()) log.debug(")HSession");
  }
  
  /**
   * Replace the current HTTP session by the given one.
   * BYPS-90 
   * @param newHttpSession New HTTP session object.
   */
  public void replaceHttpSession(HttpSession newHttpSession) {
    
    // Take over new HTTP session.
    httpSessRef.set(newHttpSession);
    
    // Add this session object to the HttpSession object of the application server.
    // Set the inactive time to the maximum of all attached sessions.
    var hsess = httpSessRef.get();
    if (hsess != null) {
      HHttpSessionObject sessObj = (HHttpSessionObject)hsess.getAttribute(HConstants.HTTP_SESSION_BYPS_SESSIONS);
      if (sessObj == null) {
        sessObj = HSessionListener.initHttpSession(hsess); 
      }
      sessObj.addSession(this);
    }
    
    // Set lifetime of the new HTTP session. 
    setMaxInactiveSeconds(getMaxInactiveSeconds());
    
    touch();
  }
  
  /**
   * Set maximum inactive seconds.
   * The inactive interval of the application server's session is extended to 
   * the maximum of all sessions. 
   * @param v inactive seconds
   */
  public void setMaxInactiveSeconds(int v) {
    maxInactiveSeconds = v;
    
    // The HttpSession inactive time must be the maximum 
    // of all attached sessions.
    var hsess = httpSessRef.get();
    if (hsess != null) {
      int inactiveSeconds = hsess.getMaxInactiveInterval();
      if (inactiveSeconds < v) {
        hsess.setMaxInactiveInterval(v);
      }
    }
  }
  
  /**
   * Get maximum inactive seconds.
   * @return inactive seconds
   */
  public int getMaxInactiveSeconds() {
    return maxInactiveSeconds;
  }

  /**
   * Remove this session from the session management.
   * Release the long-poll from.
   * Invalidate the application server's session if this is the last one attached to it.
   */
  public void done() {
    if (log.isDebugEnabled()) log.debug("done(");
    
    if (log.isDebugEnabled()) log.debug("remove sessionId=" + getTargetId().toSessionId());
    BHashMap<String, HSession> sessions = HSessionListener.getAllSessions(); 
    HSession thisSession = sessions.remove(getTargetId().toSessionId());

    // Do nothing, if session was already killed.  
    if (thisSession == null) {
      // already killed
    }
    else {

      // Remove the BYPS session from the application server's session object.
      // If no other BYPS session is attached, invalidate the server's session.
      var hsess = httpSessRef.get();
      if (hsess != null) {
        try {
          HHttpSessionObject sessObj = (HHttpSessionObject)hsess.getAttribute(HConstants.HTTP_SESSION_BYPS_SESSIONS);
          sessObj.removeSession(this);
          if (sessObj.isEmpty()) {
            hsess.invalidate();
          }
        }
        catch (Throwable e) {
          // assume HttpSession already invalidated.
        }
      }
      
      // HWireServer.done() could interrupt the current thread.
      // Delete the interrupt signal that might be set in this function.
      // If the thread has already been interrupted before, interrupt it after 
      // done() again.
      {    
        boolean intrp = Thread.currentThread().isInterrupted();
        try { 
          wireServer.done(); 
          synchronized(wireServer) { wireServer.wait(1); }
        } catch (InterruptedException ignored) {
        }
        
        if (intrp) { 
          Thread.currentThread().interrupt();
        }
      }
      
      // Stop reverse client.
      // Long-poll is released. 
      wireClientR.done();
    }
    
    if (log.isDebugEnabled()) log.debug(")done");
  }
  
  /**
   * Extend the lifetime of the session.
   */
  public void touch() {
    lastAccessTime = System.currentTimeMillis();
  }
  
  /**
   * Check if session is expired.
   * @return true, if expired.
   */
  public boolean isExpired() {
    long now = System.currentTimeMillis();
    long maxIdleMillis = (long)getMaxInactiveSeconds() * 1000;
    return lastAccessTime + maxIdleMillis < now;
  }
  
  protected BTransportFactory getTransportFactory(BApiDescriptor apiDesc) {
    BTransportFactory transportFactory = new HTransportFactoryServer(
        apiDesc, wireServer, wireClientR, serverContext.getServerRegistry());
    return transportFactory;
  }

  public void removeExpiredResources() {
    if (log.isDebugEnabled()) log.debug("removeExpiredResources(");
    boolean exp = isExpired();
    if (log.isDebugEnabled()) log.debug("sesionId=" + getTargetId().toSessionId() + ", expired=" + isExpired());
    if (exp) {
      done();
    }
    else {
      wireServer.cleanup();
      wireClientR.cleanup();
    }
    if (log.isDebugEnabled()) log.debug(")removeExpiredResources");
  }
  
//  public Collection<BClient> getForwardClientsToOtherServers() throws RemoteException {
//    return serverContext.getServerRegistry().getForwardClientsToOtherServers();
//  } unused?
//
  public void setTargetId(BTargetId v) {
    getServer().setTargetId(v);
  }
  
  public BTargetId getTargetId() {
    return getServer().getTargetId();
  }


  public static final HSession getSession(BTargetId targetId) {
    BHashMap<String, HSession> sessions = HSessionListener.getAllSessions();
    return sessions.get(targetId.toSessionId());
  }

  public abstract BServer getServer();

  /**
   * Set session authenticated.
   * Extend the inactive interval of the session to the default value.
   */
  public void setSessionAuthenticated() {
    
    // If the inactive time was not set to something different than
    // the time for unauthorized pending sessions, set it to the default
    // lifetime.
    int n = maxInactiveSeconds;
    if (n == getOptionMaxInactiveSecondsAuth()) {
      maxInactiveSeconds = n = HConstants.DEFAULT_INACTIVE_SECONDS_AUTHENTICATED;
    }
    
    setMaxInactiveSeconds(n);
  }
  
  public BClient getClientR() {
    return getServer().getClientR();
  }
  
  public String toString() {
    BServer server = getServer();
    return "[user=" + remoteUser + ", targetId=" + (server != null ? server.getTargetId() : BTargetId.ZERO) + "]";
  }
  
  public String getRemoteUser() {
    return this.remoteUser;
  }

  public HServerContext getServerContext() {
    return serverContext;
  }
  
  private static int getOptionMaxInactiveSecondsAuth() {
    int ret = HConstants.MAX_INACTIVE_SECONDS_BEFORE_AUTHENTICATED;
    try {
      String opt = System.getProperty(HConstants.OPTION_MAX_INACTIVE_SECONDS_BEFORE_AUTHENTICATED);
      if (opt != null && opt.length() != 0) {
        ret = Integer.parseInt(opt);
        if (ret <= 0) {
          ret = HConstants.MAX_INACTIVE_SECONDS_BEFORE_AUTHENTICATED;
        }
      }
    }
    catch (Exception ignored) {
    }
    return ret;
  }
  
  private final static Logger log = LoggerFactory.getLogger(HSession.class);

}
