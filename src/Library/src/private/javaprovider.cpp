//
// Copyright (C) 2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "javaprovider.h"

#ifdef Q_OS_ANDROID

#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)

#include <QJniEnvironment>
#define JENV QJniEnvironment
#define JOBJ QJniObject

#else

#include <QAndroidJniEnvironment>
#define JENV QAndroidJniEnvironment
#define JOBJ QAndroidJniObject

#endif

/**
 * @brief Get the singleton JavaProvider instance
 * 
 * Creates and returns the singleton JavaProvider instance.
 * This is thread-safe using a static local variable.
 * 
 * @return Pointer to the JavaProvider instance
 */
JavaProvider *JavaProvider::instance() {
    static JavaProvider* instance = new JavaProvider();
    return instance;
}

/**
 * @brief Request purchase of a billing item via JNI
 * 
 * This method calls the CppProvider Java class to request a purchase.
 * It uses JNI to invoke the static setWindowFlags method.
 * 
 * @param item The item identifier to purchase
 * 
 * @note This is a wrapper around JNI static method calls
 * @note The JNI method signature is: setWindowFlags(String)
 */
void JavaProvider::getBillingItem(const QString &item) const {
    auto javaItem = JOBJ::fromString(item);
    JOBJ::callStaticMethod<void>("com/quasarapp/androidtools/CppProvider",
                                 "setWindowFlags",
                                 "(Ljava/lang/String)V",
                                 javaItem.object<jstring>());
}

/**
 * @brief Constructor - Registers native methods
 * 
 * This constructor registers native methods with the Java CppProvider class.
 * It sets up the JNI interface for communication between Java and C++.
 * 
 * Registers the following native methods:
 * - purchaseReceived(String, String) - Handles purchase events
 */
JavaProvider::JavaProvider() {

    // Define native methods to register
    JNINativeMethod methods[] {
        {"purchaseReceived", "(Ljava/lang/String;Ljava/lang/String;)V", reinterpret_cast<void *>(purchaseReceived)},
    };

    // Get the CppProvider Java class
    JOBJ javaClass("com/quasarapp/androidtools/CppProvider");
    
    // Get the JNI environment
    JENV env;
    
    // Get the class object
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    
    // Register the native methods
    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    
    // Clean up the class reference
    env->DeleteLocalRef(objectClass);

}

/**
 * @brief Initialize billing on Java side
 * 
 * Calls the initBilling static method on the CppProvider Java class.
 * This should be called before performing any billing operations.
 */
void JavaProvider::initBilling() const {
    JOBJ::callStaticMethod<void>("com/quasarapp/androidtools/CppProvider",
                                 "initBilling",
                                 "()V");
}

/**
 * @brief Set window flags via JNI
 * 
 * Calls the setWindowFlags static method on the CppProvider Java class.
 * This is used for controlling Android window behavior.
 * 
 * @param flag The flag value to set
 * @param enable true to enable the flag, false to disable
 */
void JavaProvider::setWindowFlags(int flag, bool enable) const {
    JOBJ::callStaticMethod<void>("com/quasarapp/androidtools/CppProvider",
                                 "setWindowFlags", "(IZ)V", flag, enable);
}

/**
 * @brief Add a permission via JNI
 * 
 * Calls the addPermision static method on the CppProvider Java class.
 * This triggers the Android permission dialog for the specified permission.
 * 
 * @param permisionName The permission name to request
 * @return true if permission was granted, false otherwise
 */
bool JavaProvider::addPermision(const QString &permisionName) const {
    auto javaItem = JOBJ::fromString(permisionName);
    jboolean result = JOBJ::callStaticMethod<jboolean>("com/quasarapp/androidtools/CppProvider",
                                     "addPermision",
                                     "(Ljava/lang/String)Z",
                                     javaItem.object<jstring>());
    return result;

}

/**
 * @brief JNI callback for purchase events
 * 
 * This native method receives purchase events from the Java layer.
 * It extracts the purchase ID and token, then emits a Qt signal.
 * 
 * @param env The JNI environment
 * @param thiz The Java object reference (unused, marked with Q_UNUSED)
 * @param id The purchase item ID as a Java string
 * @param token The purchase validation token as a Java string
 * 
 * @note This method is called from Java thread context
 * @note The signal is emitted from Qt thread
 */
void JavaProvider::purchaseReceived(JNIEnv *env, jobject thiz, jstring id, jstring token) {
    Q_UNUSED(thiz)

    // Extract UTF-8 strings from Java strings and emit signal
    emit JavaProvider::instance()->sigPurchase(env->GetStringUTFChars(id, 0),
                                               env->GetStringUTFChars(token, 0));
}

#endif
