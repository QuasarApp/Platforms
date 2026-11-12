/**
 * @file testutils.cpp
 * @brief Implementation of test utility functions
 * 
 * This file contains the implementation of utility functions for unit testing.
 * It provides helper methods for wait operations and connection handling.
 */

/**
 * @copyright (C) 2020-2022 QuasarApp.
 * Distributed under the GPLv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, changing it is not allowed.
 */

#include "testutils.h"

#include <QCoreApplication>
#include <QDateTime>
#include <QVariantMap>

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
bool TestUtils::funcPrivateConnect(const std::function<bool ()> &requestFunc,
                                   const std::function<bool ()> &checkFunc,
                                   const std::function<QMetaObject::Connection ()> &connectFunction) const {

    QMetaObject::Connection m_connection = connectFunction();
    if (requestFunc && !requestFunc()) {
        QObject::disconnect(m_connection);
        return false;
    }

    bool return_value = TestUtils::wait(checkFunc, 10000);
    QObject::disconnect(m_connection);

    return return_value;
}

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
bool TestUtils::funcPrivateConnect(const std::function<bool ()> &requestFunc,
                                   const std::function<bool ()> &checkFunc) const {
    return funcPrivateConnect(requestFunc, checkFunc, [](){return QMetaObject::Connection();});
}

/**
 * @brief Default constructor for TestUtils
 * 
 * Initializes the test utilities.
 */
TestUtils::TestUtils()
{

}

/**
 * @brief Virtual destructor for TestUtils
 * 
 * Virtual destructor for proper cleanup.
 */
TestUtils::~TestUtils() {
}

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
bool TestUtils::wait(const std::function<bool()> &forWait, int msec) const {
    auto curmsec = QDateTime::currentMSecsSinceEpoch() + msec;
    while (curmsec > QDateTime::currentMSecsSinceEpoch() && !forWait()) {
        QCoreApplication::processEvents();
    }
    QCoreApplication::processEvents();
    return forWait();
}

