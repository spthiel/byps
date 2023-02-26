package byps.http.client.asf;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpCookie;
import java.nio.ByteBuffer;
import java.security.Principal;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;
import org.apache.http.auth.AuthSchemeProvider;
import org.apache.http.auth.AuthScope;
import org.apache.http.auth.Credentials;
import org.apache.http.client.config.AuthSchemes;
import org.apache.http.client.protocol.HttpClientContext;
import org.apache.http.config.Lookup;
import org.apache.http.config.RegistryBuilder;
import org.apache.http.impl.auth.SPNegoSchemeFactory;
import org.apache.http.impl.client.BasicCookieStore;
import org.apache.http.impl.client.BasicCredentialsProvider;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.DefaultHttpRequestRetryHandler;
import org.apache.http.impl.client.HttpClientBuilder;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.client.WinHttpClients;
import org.apache.http.impl.conn.PoolingHttpClientConnectionManager;
import org.apache.http.impl.cookie.BasicClientCookie;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import byps.BAsyncResult;
import byps.BContentStream;
import byps.BSyncResult;
import byps.http.HConstants;
import byps.http.client.HHttpClient;
import byps.http.client.HHttpRequest;

/**
 * HHttpClient implementation using Apache HTTP Components.
 * 
 * SSO Auth: http://stackoverflow.com/questions/24633380/how-do-i-authenticate-with-spnego-kerberos-and-apaches-httpclient
 */
public class AsfClient implements HHttpClient {

  private static Logger log = LoggerFactory.getLogger(AsfClient.class);
  private final CloseableHttpClient httpclient;
  private final HttpClientContext context;

  public AsfClient(String url) {
    if (log.isDebugEnabled()) log.debug("AsfClient(");
    httpclient = internalCreateHttpClient();
    context = internalCreateSSOContext();
    
    // We do not use this call ... because it needs a lot of time under Notes JVM.
    // httpclient = HttpClients.createSystem();
    if (log.isDebugEnabled()) log.debug(")AsfClient");
  }
  
  private static boolean isWindows() {
    String os = System.getProperty("os.name");
    return os != null && os.toLowerCase().contains("windows");
  }
  
  private static CloseableHttpClient internalCreateHttpClient() {
    if (log.isDebugEnabled()) log.debug("internalCreateHttpClient(");

    String maxConnStr = System.getProperty("http.maxConnections");
    int maxConnections = maxConnStr != null && maxConnStr.length() != 0 ? Integer.parseInt(maxConnStr) : 100;
    log.info("maxConnections=" + maxConnections);
    
    HttpClientBuilder httpClientBuilder = null;
    
    // Use special classes for Windows.
    if (isWindows()) {
      httpClientBuilder = WinHttpClients.custom();
    }
    else {
      // if the port does not match the kerberos database entry, skip it during the lookup
      log.info("Register SPNEGO (Negotate) over JAAS");
      boolean skipPortAtKerberosDatabaseLookup = true;
      RegistryBuilder<AuthSchemeProvider> builder = RegistryBuilder.<AuthSchemeProvider>create();
      builder.register(AuthSchemes.SPNEGO, new SPNegoSchemeFactory(skipPortAtKerberosDatabaseLookup));

      Lookup<AuthSchemeProvider> authSchemeRegistry = builder.build();
      httpClientBuilder = HttpClients.custom().setDefaultAuthSchemeRegistry(authSchemeRegistry);
    }
    
    httpClientBuilder.setRetryHandler(new DefaultHttpRequestRetryHandler(3, true));

    // SSO über SPNEGO/Kerberos funktioniert nur, wenn der Test unter einem Windows-Benutzerkonto l�uft, dass nicht lokaler Administrator ist.

    PoolingHttpClientConnectionManager cm = new PoolingHttpClientConnectionManager();
    cm.setMaxTotal(maxConnections);
    cm.setDefaultMaxPerRoute(maxConnections);
    CloseableHttpClient httpClient = httpClientBuilder.setConnectionManager(cm).build();

    if (log.isDebugEnabled()) log.debug(")internalCreateHttpClient");
    return httpClient;
  }
  
  private static HttpClientContext internalCreateSSOContext() {
    
    if (log.isDebugEnabled()) log.debug("internalCreateSSOContext(");

    //System.setProperty("java.security.krb5.conf", "C:\\Windows\\krb5.ini");
    //System.setProperty("sun.security.krb5.debug", "true");
    System.setProperty("javax.security.auth.useSubjectCredsOnly","false");

    HttpClientContext context = HttpClientContext.create();
    
    if (!isWindows()) {

      if (log.isDebugEnabled()) log.debug("set JAAS credential provider");

      // This may seem odd, but specifying 'null' as principal tells java to use the logged in user's credentials
      Credentials useJaasCreds = new Credentials() {
        public String getPassword() { return null; }
        public Principal getUserPrincipal() { return null; }
      };

      BasicCredentialsProvider credentialsProvider = new BasicCredentialsProvider();
      credentialsProvider.setCredentials( new AuthScope(null, -1, null), useJaasCreds );
      context.setCredentialsProvider(credentialsProvider);
    }
    
    if (log.isDebugEnabled()) log.debug(")internalCreateSSOContext");
    return context;
  }

  @Override
  public void done() {
    try {
      httpclient.close();
    }
    catch (IOException e) {
    }
  }

  @Override
  public HHttpRequest get(long trackingId, String url, BAsyncResult<ByteBuffer> asyncResult) {
    return new AsfGet(trackingId, url, asyncResult, httpclient, context);
  }

  @Override
  public HHttpRequest getStream(long trackingId, String url,
      BAsyncResult<BContentStream> asyncResult) {
    return new AsfGetStream(trackingId, url, asyncResult, httpclient, context);
  }

  @Override
  public HHttpRequest post(long trackingId, String url, ByteBuffer buf,
      BAsyncResult<ByteBuffer> asyncResult) {
    return new AsfPost(trackingId, url, buf, asyncResult, httpclient, context);
  }

  @Override
  public HHttpRequest putStream(long trackingId, String url, InputStream stream,
      BAsyncResult<ByteBuffer> asyncResult) {
    return new AsfPutStream(trackingId, url, stream, asyncResult, httpclient, context);
  }
  
  @Override
  public String getHttpSession() {
    String ret = "";
    org.apache.http.client.CookieStore cookieStore = context.getCookieStore();
    if (cookieStore != null) {
      for (org.apache.http.cookie.Cookie cookie : cookieStore.getCookies()) {
        // JSESSIONID=EDAF441A80ECC88EC4D1414AFCDD1AD0; Path=/ix-elo200; HttpOnly
        if (cookie.getName().equals(HConstants.HTTP_COOKIE_JSESSIONID) && cookie instanceof BasicClientCookie) {
          BasicClientCookie bcookie = (BasicClientCookie)cookie;
          ret = bcookie.getValue();
        }
      }
    }
    return ret;
  }
  
  /**
   * {@inheritDoc}
   */
  @Override
  public HttpCookie getHttpCookie(String name) {
    Optional<org.apache.http.cookie.Cookie> opt = internalFindCookie(name);
    return opt.map(this::toHttpCookie).orElse(null);
  }

  /**
   * {@inheritDoc}
   */
  @Override
  public void setHttpCookie(HttpCookie cookie) {
    if (cookie != null) {

      if (context.getCookieStore() != null) {
        
        // ASF cookie store does not support to remove a cookie.
        // If the given cookie exists, we create a copy of the cookie store without the cookie. 
      
        Optional<org.apache.http.cookie.Cookie> optOldCookie = internalFindCookie(cookie.getName());
        optOldCookie.ifPresent(oldCookie -> {
          
          BasicCookieStore cookieStoreNew = new BasicCookieStore();
          
          context.getCookieStore().getCookies().stream()
            .filter(c -> c != oldCookie)
            .forEach(cookieStoreNew::addCookie);
            
          context.setCookieStore(cookieStoreNew);
        });

      }
      else {
        context.setCookieStore(new BasicCookieStore());
      }
      
      org.apache.http.cookie.Cookie httpCookie = fromHttpCookie(cookie);
      context.getCookieStore().addCookie(httpCookie);
    }
  }

  /**
   * Find cookie with given name.
   * @param name cookie name
   * @return Cookie object
   */
  private Optional<org.apache.http.cookie.Cookie> internalFindCookie(String name) {
    Optional<org.apache.http.cookie.Cookie> ret = Optional.empty();
  
    if (context.getCookieStore() != null) {
      ret = context.getCookieStore().getCookies().stream()
        .filter(c -> c.getName().equalsIgnoreCase(name)).findFirst();
    }
    
    return ret;
  }
  
  /**
   * Convert ASF cookie into HttpCookie.
   * Copies domain, path, secure, into HttpCookie.
   * Always sets attribute HttpOnly.
   * BYPS-18.
   * @param apacheCookie ASF cookie
   * @return HttpCookie
   */
  private HttpCookie toHttpCookie(org.apache.http.cookie.Cookie apacheCookie) {
    HttpCookie cookie = new HttpCookie(apacheCookie.getName(), apacheCookie.getValue());
    cookie.setDomain(apacheCookie.getDomain());
    cookie.setPath(apacheCookie.getPath());
    cookie.setSecure(apacheCookie.isSecure());
    cookie.setHttpOnly(true);
    return cookie;
  }

  /**
   * Convert HttpCookie into ASF cookie object.
   * Copies domain, path, secure, HttpOnly into ASF cookie.
   * BYPS-18.
   * @param cookie jHttpCookie
   * @return ASF cookie
   */
  private org.apache.http.cookie.Cookie fromHttpCookie(HttpCookie cookie) {
    BasicClientCookie apacheCookie = new BasicClientCookie(cookie.getName(), cookie.getValue());
    apacheCookie.setDomain(cookie.getDomain());
    apacheCookie.setPath(cookie.getPath());
    apacheCookie.setSecure(cookie.getSecure());
    if (cookie.isHttpOnly()) {
      apacheCookie.setAttribute("HttpOnly", null);
    }
    return apacheCookie;
  }

  public static void main(String[] args)  {
    try {
      //String url = "http://srvtdev03:6020/ix-elo90";
      //String url = "http://srvpelo1:6080/ix-lldo_prod";
      String url = "http://localhost:8084/ix-elo90";
      AsfClient client = new AsfClient(url + "/ix");
      BSyncResult<ByteBuffer> asyncResult = new BSyncResult<ByteBuffer>();
      client.get(4, url + "/bypsauth/auth?streamversion=8&responseformat=html&logout=true", asyncResult).run();
      ByteBuffer bbuf = asyncResult.getResult();
      System.out.println(new String(bbuf.array(), "UTF-8"));
    }
    catch (Throwable e) {
      e.printStackTrace();
    }
  }

  @Override
  public List<HttpCookie> getHttpCookies() {
    return context.getCookieStore().getCookies().stream()
      .map(this::toHttpCookie).collect(Collectors.toList());
  }

  @Override
  public void setHttpCookies(List<HttpCookie> cookies) {
    BasicCookieStore cookieStoreNew = new BasicCookieStore();
    
    cookies.stream()
      .map(this::fromHttpCookie)
      .forEach(cookieStoreNew::addCookie);
      
    context.setCookieStore(cookieStoreNew);
  }

}
