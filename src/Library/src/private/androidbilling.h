//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef ANDROIDBILLING_H
#define ANDROIDBILLING_H

#include <QtGlobal>

#ifdef Q_OS_ANDROID

#include <QObject>

#include <Platforms/ibilling.h>

// Forward declaration
class JavaProvider;

/**
 * @class AndroidBilling
 * @brief Android-specific implementation of IBilling interface
 * 
 * This class provides Android-specific in-app purchase functionality.
 * It implements the IBilling interface and handles all Android billing
 * operations including purchase requests, purchase validation, and event handling.
 * 
 * @note This class inherits from IBilling and QObject.
 * @note Uses JavaProvider for JNI interactions with Android Java layer.
 * @note Implements the Google Play Billing Library integration.
 * 
 * @subpage android_billing
 * 
 * @since 3.0.0
 */
class AndroidBilling : public Platforms::IBilling
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for AndroidBilling
     * 
     * Initializes the Android billing instance and sets up JavaProvider.
     */
    AndroidBilling();

    /**
     * @brief Initialize Android billing system
     * 
     * Sets up the Google Play Billing Library and prepares for purchases.
     * This method should be called before using any billing functionality.
     */
    void init() override;

public slots:
    /**
     * @brief Request purchase of an item on Android
     * 
     * Initiates the purchase flow for the specified item ID using Google Play Billing.
     * This method handles the Android-specific purchase dialog and flow.
     * 
     * @param itemID The unique identifier of the item to purchase
     * 
     * @note This is the Android implementation of IBilling::getItem()
     */
    void getItem(const QString &itemID) override;

    /**
     * @brief Check if billing is supported on Android
     * 
     * Returns true if Google Play Billing is available and initialized.
     * 
     * @return true if billing is supported, false otherwise
     */
    bool isSupported() override;

private slots:
    /**
     * @brief Handle purchase received event
     * 
     * This slot is called when a purchase event is received from the Java layer.
     * It processes the purchase and emits the sigPurchaseReceived signal.
     * 
     * @param id The purchase item ID
     * @param token The purchase validation token
     */
    void handlePurchaseReceived(QString id, QString token);

private:
    /**
     * @brief Get the public key for purchase validation
     * 
     * Returns the public key used to validate purchase tokens.
     * 
     * @return Pointer to the public key string
     */
    const char* getPublicKey();

    /**
     * @brief Java provider for JNI interactions
     * 
     * Pointer to JavaProvider instance used for JNI calls.
     */
    JavaProvider *_javaProvider = nullptr;

};

#endif

#endif // ANDROIDBILLING_H
