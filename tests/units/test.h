//#
//# 2021-2027 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#ifndef TEST_H
#define TEST_H

/**
 * @class Test
 * @brief Base abstract class for unit tests
 * 
 * This class provides the base interface for all unit tests in the Platforms library.
 * It defines the test() method that must be implemented by all test classes.
 * 
 * @note This is an abstract class that should not be instantiated directly.
 * @note Derived classes must implement the virtual test() method.
 * 
 * @since 2020
 */
class Test
{
public:
    /**
     * @brief Default constructor
     * 
     * Default constructor for the Test base class.
     * Derived classes should override this if custom initialization is needed.
     */
    Test() = default;
    
    /**
     * @brief Virtual destructor
     * 
     * Virtual destructor to ensure proper cleanup of derived class objects.
     */
    virtual ~Test() = default;
    
    /**
     * @brief Execute the test case
     * 
     * This pure virtual method must be implemented by all derived classes.
     * It should contain the test logic and assertions using QtTest macros.
     * 
     * @note This method is used by the test framework to run individual test cases.
     * @note Use QVERIFY, QFAIL, QWARN macros from <QtTest> for assertions.
     * 
     * @see QVERIFY, QFAIL, QWARN
     */
    virtual void test() = 0;
};

#endif // TEST_H
