package byps.http.cotest;

import java.lang.reflect.Method;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import byps.BApiDescriptor;
import byps.BAsyncResult;
import byps.BClient;
import byps.log.LogConfigurator;

public class CoTestParams {
  
  private BApiDescriptor apiDesc;
  private int port;
  private String bypstest_jar;
  private String url;
  private CoTestRunnable testRunnable;
  private String logFileOther;
  
  public void initTestSite(final BApiDescriptor apiDesc, String bypstest_jar, int port, String logFileOther) throws Exception {
    this.apiDesc = apiDesc;
    this.bypstest_jar = bypstest_jar;
    this.port = port;
    this.url = "http://localhost:" + port + "/comptest/bypsservlet";
    this.logFileOther = logFileOther;

    this.testRunnable = new CoTestRunnable() {
      public void run(BClient client, BAsyncResult<Boolean> asyncResult) {
        try {
          Class<?> serverClass = Class.forName(apiDesc.basePackage + ".TestCompatibleApi_" + apiDesc.name);
          Method m = serverClass.getMethod("test", BClient.class);
          m.invoke(null, client);
          asyncResult.setAsyncResult(Boolean.TRUE, null);
        }
        catch (Exception e) {
          asyncResult.setAsyncResult(null, e);
        }
      }
    };
  }
  
  public void initProcessSite(String apiDescClassName, int port, String url, String logFile) throws Exception {

    if (logFile.length() != 0) {
      LogConfigurator.initFile("info", logFile);
      Logger log = LoggerFactory.getLogger(CoTestProcess.class);
      log.info("process started");
    }

    Class<?> apiDescClass = Class.forName(apiDescClassName);
    Method apiDescInstance = apiDescClass.getMethod("instance");
    apiDesc = (BApiDescriptor)apiDescInstance.invoke(null);
    initTestSite(apiDesc, "", port, "");
    this.url = url;
  }

  public BApiDescriptor getApiDesc() {
    return apiDesc;
  }

  public void setApiDesc(BApiDescriptor apiDesc) {
    this.apiDesc = apiDesc;
  }

  public int getPort() {
    return port;
  }

  public void setPort(int port) {
    this.port = port;
  }

  public String getBypstest_jar() {
    return bypstest_jar;
  }

  public void setBypstest_jar(String bypstest_jar) {
    this.bypstest_jar = bypstest_jar;
  }

  public String getUrl() {
    return url;
  }

  public void setUrl(String url) {
    this.url = url;
  }

  public CoTestRunnable getTestRunnable() {
    return testRunnable;
  }

  public void setTestRunnable(CoTestRunnable testRunnable) {
    this.testRunnable = testRunnable;
  }

  public String getApiDescClassName() {
    return apiDesc.basePackage + ".BApiDescriptor_" + apiDesc.name;
  }

  public String getLogFileOther() {
    return logFileOther;
  }

  public void setLogFileOther(String logFile) {
    this.logFileOther = logFile;
  }
}
