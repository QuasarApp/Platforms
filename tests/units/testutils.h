//#
//# Copyright (C) 2020-2022 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#ifndef TESTUTILS_H
#define TESTUTILS_H

#include "functional"
#include <QMetaObject>

/**
 * @class TestUtils
 * @brief Utility class for unit testing
 * 
 * This class provides helper methods for unit testing, including:
 * - Wait functionality for asynchronous operations
 * - Connection helper methods
 * 
 * @note This class is designed to be used with QtTest framework.
 * @note Methods are thread-safe for basic operations.
 * 
 * @since 2020
 */
class TestUtils
{
public:
    /**
     * @brief Default constructor
     * 
     * Initializes the test utilities.
     */
    TestUtils();
    
    /**
     * @brief Virtual destructor
     * 
     * Virtual destructor for proper cleanup.
     */
    virtual ~TestUtils();
    
    /**
     * @brief Wait for a condition to become true
     * 
     * Continuously checks the provided function until it returns true
     * or the timeout is reached. This is useful for waiting on
     * asynchronous operations to complete.
     * 
     * @param forWait A function that returns true when the condition is met
     * @param msec Maximum time to wait in milliseconds
     * @return true if the condition was met within the timeout, false otherwise
     * 
     * @note Process events while waiting to ensure Qt event loop works properly
     * @example
     * if (testUtils.wait([this]{ return !isLoading; }, 5000)) {
     *     // Loading completed
     * }
     */
    bool wait(const std::function<bool()> &forWait, int msec) const;

    /**
     * @brief Helper for private connect operations with three functions
     * 
     * This method is used internally for handling private connect operations.
     * It connects a request function and waits for a check function to return true.
     * 
     * @param requestFunc Function to perform the request operation
     * @param checkFunc Function to check if the operation completed successfully
     * @param connectFunction Function that creates the connection
     * @return true if the check function returned true, false otherwise
     * 
     * @note This method handles connection cleanup automatically
     * @note The checkFunc is called periodically until it returns true or timeout
     */
    bool funcPrivateConnect(const std::function<bool ()> &requestFunc,
                            const std::function<bool ()> &checkFunc,
                            const std::function<QMetaObject::Connection ()> &connectFunction) const;

    /**
     * @brief Helper for private connect operations with two functions
     * 
     * Convenience overload that creates an empty connection for the third parameter.
     * Uses the same logic as funcPrivateConnect but with simplified parameters.
     * 
     * @param requestFunc Function to perform the request operation
     * @param checkFunc Function to check if the operation completed successfully
     * @return true if the check function returned true, false otherwise
     */
    bool funcPrivateConnect(const std::function<bool ()> &requestFunc,
                            const std::function<bool ()> &checkFunc) const;
};

#endif // TESTUTILS_H
