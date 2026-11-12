//#
//# 2021-2027 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#ifndef EXAMPLE_TEST_H
#define EXAMPLE_TEST_H
#include "test.h"
#include "testutils.h"

#include <QtTest>

/**
 * @class ExampleTest
 * @brief Example unit test class
 * 
 * This class demonstrates how to write unit tests using QtTest framework.
 * It inherits from the Test base class and uses TestUtils for helper functions.
 * 
 * @inheritance Test
 * @inheritance TestUtils
 * 
 * @note This is an example test that should be used as a template for writing tests.
 * @note Extend this class with your own test cases.
 * 
 * @since 2020
 */
class ExampleTest: public Test, protected TestUtils
{
public:
    /**
     * @brief Default constructor
     * 
     * Initializes the example test.
     */
    ExampleTest();
    
    /**
     * @brief Virtual destructor
     * 
     * Virtual destructor for proper cleanup.
     */
    ~ExampleTest();

    /**
     * @brief Execute the example test
     * 
     * This method performs a simple test assertion to verify the test framework works.
     * It should be overridden with actual test logic.
     * 
     * @note This is a placeholder test - replace with actual test cases.
     * @see Test::test
     */
    void test();

};

#endif // EXAMPLE_TEST_H
