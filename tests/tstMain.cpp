/**
 * @file tstMain.cpp
 * @brief Main test class implementation
 * 
 * This file contains the implementation of the main test runner class.
 * It initializes and executes unit tests using QtTest framework.
 */

/**
 * @copyright (C) 2020-2022 QuasarApp.
 * Distributed under the GPLv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, changing it is not allowed.
 */

#include <QtTest>
#include "exampletest.h"

/**
 * @brief Macro for initializing test cases
 * 
 * This macro simplifies the process of initializing and running test cases.
 * It creates a new instance of the specified test class and passes it to initTest().
 * 
 * @param name The name of the test function
 * @param testClass The test class to instantiate
 * 
 * @note Use this macro to add test cases to your test suite
 * @example
 * TestCase(myTest, MyTestClass)
 */
#define TestCase(name, testClass) \
    void name() { \
        initTest(new testClass()); \
    }

/**
 * @class tstMain
 * @brief Main test runner class
 * 
 * This class serves as the main entry point for running unit tests.
 * It manages the Qt application lifecycle and executes test cases.
 * 
 * @inheritance QObject
 * 
 * @note This class is used with QTEST_APPLESS_MAIN macro for QtTest.
 * @note All test cases should be registered in the private slots section.
 * 
 * @since 2020
 */
class tstMain : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for tstMain
     * 
     * Initializes the test runner and sets up the QCoreApplication.
     * Prepares the application for running tests.
     */
    tstMain();

    /**
     * @brief Destructor for tstMain
     * 
     * Cleans up resources and exits the application.
     */
    ~tstMain();

private slots:
    /**
     * @brief Test case registration section
     * 
     * All test cases should be registered in this section using the TestCase macro.
     * 
     * @note Add new test cases by uncommenting and modifying the TestCase macro.
     */
    // BEGIN TESTS CASES
    TestCase(exampleTest, ExampleTest)
    // END TEST CASES

private:
    /**
     * @brief Initialize test runner
     * 
     * Prepares the test environment and initializes the QCoreApplication.
     * Sets up the application name and organization name.
     * 
     * @param test Pointer to the test class instance to run
     * 
     * @note This method runs the test in a QTimer singleShot to ensure proper event processing
     * @note The application is exited after the test completes
     */
    void initTest(Test* test);

    /**
     * @brief QCoreApplication instance
     * 
     * Application instance used for running tests.
     */
    QCoreApplication *_app = nullptr;
};

/**
 * @brief Constructor for tstMain
 * 
 * Initializes the test runner and sets up the QCoreApplication.
 * Prepares the application for running tests.
 * 
 * @note Sets application name to "testPlatforms"
 * @note Sets organization name to "QuasarApp"
 * @note Removes existing data in AppDataLocation to ensure clean test environment
 */
tstMain::tstMain() {

    // init xample unit test
    int argc =0;
    char * argv[] = {nullptr};

    _app = new QCoreApplication(argc, argv);
    QCoreApplication::setApplicationName("testPlatforms");
    QCoreApplication::setOrganizationName("QuasarApp");

    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    QDir(path).removeRecursively();

}

/**
 * @brief Destructor for tstMain
 * 
 * Exits the application and cleans up resources.
 */
tstMain::~tstMain() {
    _app->exit(0);
    delete _app;
}

/**
 * @brief Initialize test and run it
 * 
 * Runs the specified test case asynchronously using QTimer.
 * This ensures proper event processing during test execution.
 * 
 * @param test Pointer to the test class instance to run
 * 
 * @note The test is executed in a separate timer event
 * @note The application is exited after the test completes
 * @note This method is called automatically by the TestCase macro
 */
void tstMain::initTest(Test *test) {
    QTimer::singleShot(0, this, [this, test]() {
        test->test();
        delete test;
        _app->exit(0);
    });

    _app->exec();
}

QTEST_APPLESS_MAIN(tstMain)

#include "tstMain.moc"
