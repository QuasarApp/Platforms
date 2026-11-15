//#
//# Copyright (C) 2021-2027 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "androidbilling.h"
#include "javaprovider.h"



#ifdef Q_OS_ANDROID
#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
#include <QJniEnvironment>
#else
#include <QAndroidJniEnvironment>
#endif
#include <QObject>

// Play Market public license key.
static const char* publick_key = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAiooKz+RwMhtk0quCzKVlUza1kgVEYtoNPz9tfn/JCRVH5+PibFPF3uv9Th9ts8ikyr9Yiz13vaVbQO4NQ6Gf0SgqTOpHwYGyDnSZSkPSYkH5KcXpXNVZzkQvrcBU10D8m6QJqnWfnFYsvtt90axO9/yf1Y7EeIvH3+gQ9VkJezclfG3CJb41l4gg2JKqOCHdGBBo0RWNe9mKBKzhSodlXY+3bjXnbYUZOwn1+KxNdiFgzlSLW3jdJ0IuuEe8dmxiWJLP6CW5qed61wzHQwKhsJYlno/d/NfFu6RSBGKFmwPV4gZWDB46pOVJsOFNSd5XhzZjVpNyN1NOT6ws7nd6GQIDAQAB";

/**
 * @brief Constructor for AndroidBilling
 * 
 * Initializes the Android billing instance and sets up the JavaProvider.
 * Connects to the purchase signal from JavaProvider.
 */

    _javaProvider = JavaProvider::instance();

    connect(_javaProvider, &JavaProvider::sigPurchase,
            this, &AndroidBilling::handlePurchaseReceived);

}

void AndroidBilling::init()
{
    _javaProvider->initBilling();
}

/**
 * @brief Request purchase of an item
 * 
 * This is the Android implementation of the IBilling::getItem() method.
 * It initiates the purchase flow for the specified item ID.
 * 
 * @param itemID The unique identifier of the item to purchase
 */
void AndroidBilling::getItem(const QString& itemID)
{
    _javaProvider->getBillingItem(itemID);
}

/**
 * @brief Handle purchase received event
 * 
 * This slot handles purchase events received from the Java layer.
 * It processes the purchase data and emits the appropriate signal.
 * 
 * @param id The purchase item ID
 * @param token The purchase validation token
 */
void AndroidBilling::handlePurchaseReceived(QString id, QString token)
{
    // Emit the purchase received signal to notify observers
    emit sigPurchaseReceived(Platforms::Purchase{id, token});
}

/**
 * @brief Get the public key for validation
 * 
 * Returns the public key used to validate purchase tokens.
 * This should be implemented to return the actual public key.
 * 
 * @return Pointer to the public key string
 */
const char* AndroidBilling::getPublicKey()
{
    return publick_key;
}

/**
 * @brief Check if billing is supported
 * 
 * Returns true if Google Play Billing is available and properly configured.
 * 
 * @return true if billing is supported, false otherwise
 */
bool AndroidBilling::isSupported()
{
    return true;
}


#endif
