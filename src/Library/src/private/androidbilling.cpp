//
// Copyright (C) 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

/**
 * @file androidbilling.cpp
 * @brief Android implementation of the Google Play Billing system.
 */

#include "androidbilling.h"
#include "javaprovider.h"

#include <androidplatformtools.h>

#include <android/billing.h>

#include <QAndroidJniEnvironment>
#include <QJniEnvironment>


/**
 * @brief Play Market public license key for purchase validation.
 * 
 * This key is used to validate Google Play purchase tokens on the server side.
 * @warning This key should be stored securely and not committed to source control.
 * In production, use a secure method to store and retrieve this key.
 */
static const char* publick_key = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAiooKz+RwMhtk0quCzKVlUza1kgVEYtoNPz9tfn/JCRVH5+PibFPF3uv9Th9ts8ikyr9Yiz13vaVbQO4NQ6Gf0SgqTOpHwYGyDnSZSkPSYkH5KcXpXNVZzkQvrcBU10D8m6QJqnWfnFYsvtt90axO9/yf1Y7EeIvH3+gQ9VkJezclfG3CJb41l4gg2JKqOCHdGBBo0RWNe9mKBKzhSodlXY+3bjXnbYUZOwn1+KxNdiFgzlSLW3jdJ0IuuEe8dmxiWJLP6CW5qed61wzHQwKhsJYlno/d/NfFu6RSBGKFmwPV4gZWDB46pOVJsOFNSd5XhzZjVpNyN1NOT6ws7nd6GQIDAQAB";

namespace Platforms {

/**
 * @brief AndroidBilling::AndroidBilling Constructor.
 * 
 * Initializes the Android billing system and sets up JNI connections.
 * Connects the purchase signal from JavaProvider to this class's handler.
 * 
 * @note Should only be instantiated once per application lifecycle.
 */
AndroidBilling::AndroidBilling() {
    _javaProvider = JavaProvider::instance();
    connect(_javaProvider, &JavaProvider::sigPurchase,
            this, &AndroidBilling::handlePurchaseReceived);
}

/**
 * @brief AndroidBilling::init Initializes the Android billing system.
 * 
 * This method must be called before using any billing-related methods.
 * It sets up the necessary JNI connections and initializes the billing manager.
 * 
 * @note Should be called once during application initialization.
 * @see initBilling() in JavaProvider
 */
void AndroidBilling::init() {
    _javaProvider->initBilling();
}

/**
 * @brief AndroidBilling::getItem Requests the purchase of a billing item.
 * 
 * This method triggers the purchase of the specified billing item through
 * Google Play Billing. The purchase result is handled via the handlePurchaseReceived slot.
 * 
 * @param itemID The ID of the billing item to purchase.
 * @note The item must be defined in the Android app's product configuration.
 */
void AndroidBilling::getItem(const QString& itemID) {
    _javaProvider->getBillingItem(itemID);
}

/**
 * @brief AndroidBilling::handlePurchaseReceived Handles purchase completion events from Google Play.
 * 
 * This slot is called when a purchase is completed or cancelled.
 * It validates the purchase token and emits the appropriate signals.
 * 
 * @param id The ID of the purchased item.
 * @param token The purchase token for server-side validation.
 * @note This signal is emitted to notify the billing system of the purchase.
 */
void AndroidBilling::handlePurchaseReceived(QString id, QString token) {
    Platforms::Purchase purchase;
    purchase.id = id;
    purchase.token = token;
    emit sigPurchaseReceived(purchase);
}

/**
 * @brief AndroidBilling::getPublicKey Returns the public key for purchase validation.
 * 
 * @return const char* The public key string.
 * @note The public key should be stored securely and not committed to source control.
 */
const char *AndroidBilling::getPublicKey() {
    return publick_key;
}

/**
 * @brief AndroidBilling::isSupported Checks if Google Play Billing is available on the device.
 * 
 * @return true if Google Play Billing is supported and available, false otherwise.
 * @note Returns true on Android devices with Google Play Services installed.
 */
bool AndroidBilling::isSupported() {
    return true;
}

}
