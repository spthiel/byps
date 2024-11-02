/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */
#include "AllTests.h"

#include "testfw.hpp"
#include "BLogger.hpp"
#include "Byps.hpp"
#include "Bypshttp.hpp"

#include "Testser-api.h"



LOGGER_IMPL

using namespace byps;

void AllTests_run(void *app) {
//    BLogger::init("/home/wolfgang/log/cppclient.txt", BLogLevel::Debug, false);
    BLogger::init("./log/cppclient.log", BLogLevel::Info, false);

    BLogger log("AllTests");
    log.debug() << L"AllTest_run(";

    for (int i = 0; i < 100; i++) {
		cout << "loop " << (i+1) << endl;
		TestSuite suite;

//    suite.add(TestRemoteServerR_create(app));
    suite.add(TestRemoteWithAuthentication_create(app));
        suite.add(TestRemoteStreams_create(app));
        suite.add(TestRemotePrimitiveTypes_create(app));
        suite.add(TestRemoteConstants_create(app));
        suite.add(TestRemoteEnums_create(app));
        suite.add(TestRemoteInlineInstance_create(app));
        suite.add(TestRemoteArrays_create(app));
        suite.add(TestRemoteSetTypes_create(app));
        suite.add(TestRemoteMapTypes_create(app));
        suite.add(TestRemoteArrays4Dim_create(app));
        suite.add(TestRemoteListTypes_create(app));

		suite.run();
	}


	l_info << "test suite finished";

    log.debug() << L")AllTest_run";
	BLogger::done();

	//char ret;
	//std::cin >> ret;
}
