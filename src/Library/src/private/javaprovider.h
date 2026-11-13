//
// Copyright (C) 2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef JAVAPROVIDER_H
#define JAVAPROVIDER_H

#include <QtGlobal>

#ifdef Q_OS_ANDROID

#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
#include <QJniObject>
#else
#include <QAndroidJniObject>
#endif

#include <QObject>

/**
 * @class JavaProvider
 * @brief JNI bridge between C++ and Android Java layer
 * 
 * This class provides a bridge between the C++ Qt layer and the Android
 * Java layer using JNI (Java Native Interface). It handles native method
 * registration and JNI calls for platform-specific functionality.
 * 
 * @note This class inherits from QObject to support Qt signals.
 * @note Uses singleton pattern for instance management.
 * @note Thread-safe for JNI operations.
 * 
 * @subpage jni_concepts
 * 
 * @since 3.0.0
 */
class JavaProvider : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Get the JavaProvider instance
     * 
     * Returns the singleton JavaProvider instance.
     * Creates the instance if it doesn't exist.
     * 
     * @return Pointer to JavaProvider instance
     * 
     * @note This method is thread-safe and uses a static local variable
     */
    static JavaProvider* instance();

    /**
     * @brief Request purchase of a billing item
     * 
     * Initiates the purchase flow for the specified item on the Java side.
     * This is a no-op in the C++ layer and delegates to Java.
     * 
     * @param item The identifier of the item to purchase
     */
    void getBillingItem(const QString& item) const;

    /**
     * @brief Initialize the billing system
     * 
     * Triggers the billing initialization on the Java side.
     * This should be called before performing any billing operations.
     */
    void initBilling() const;

    /**
     * @brief Set window flags
     * 
     * Sets the specified window flag on the Android window.
     * Used for controlling screen dimming and other window behaviors.
     * 
     * @param flag The window flag to set (e.g., FLAG_KEEP_SCREEN_ON)
     * @param enable true to enable the flag, false to disable
     */
    void setWindowFlags(int flag, bool enable) const;

    /**
     * @brief Add a permission to the app
     * 
     * Requests a specific permission from the Android system.
     * This triggers the system permission dialog.
     * 
     * @param permisionName The name of the permission to request
     * @return true if permission was granted, false otherwise
     */
    bool addPermision(const QString& permisionName) const;

signals:
    /**
     * @brief Signal emitted when a purchase is received
     * 
     * This signal is emitted when a purchase is detected via JNI.
     * The signal is forwarded from the Java purchaseReceived callback.
     * 
     * @param id The purchase item ID
     * @param token The purchase validation token
     * 
     * @note Connect to this signal to handle purchase events
     */
    void sigPurchase(QString id, QString token);

private:
    /**
     * @brief Default constructor
     * 
     * Registers native methods with the Java layer.
     * This should only be called from the singleton instance.
     */
    JavaProvider();

    /**
     * @brief JNI callback for purchase events
     * 
     * Native method that receives purchase events from Java.
     * Forwards the event to the Qt signal system.
     * 
     * @param env The JNI environment
     * @param thiz The Java object reference (unused)
     * @param id The purchase item ID as jstring
     * @param token The validation token as jstring
     */
    static void purchaseReceived(JNIEnv *env, jobject thiz, jstring id, jstring token);
};

#endif

#endif // JAVAPROVIDER_H
