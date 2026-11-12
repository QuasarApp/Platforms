//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "androidplatformtools.h"
#include <QCoreApplication>

#ifdef Q_OS_ANDROID

#include "javaprovider.h"

#if QT_VERSION >= QT_VERSION_CHECK(6, 2, 0)
#include <QJniEnvironment>
#include <QJniObject>
#include <QJniEnvironment>
#define JENV QJniEnvironment
#define JOBJ QJniObject
#else
#include <QAndroidJniEnvironment>
#include <QtAndroid>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>

#define JENV QAndroidJniEnvironment
#define JOBJ QAndroidJniObject
#endif
#include <QObject>

namespace Platforms {

/**
 * @brief Constructor for AndroidPlatformTools
 * 
 * Initializes the Android platform tools and sets up the JavaProvider
 * instance for JNI interactions.
 */
AndroidPlatformTools::AndroidPlatformTools() {
    _javaProvider = JavaProvider::instance();
}

/**
 * @brief Set screen dim mode on Android
 * 
 * Controls whether the screen should dim when the app is in background.
 * Uses FLAG_KEEP_SCREEN_ON flag to prevent screen dimming.
 * 
 * @param enable true to prevent screen dimming, false to allow dimming
 * 
 * @note This method uses JNI to call Java code
 * @note FLAG_KEEP_SCREEN_ON constant value is 128
 */
void AndroidPlatformTools::setScreanDim(bool enable) const {
    const int FLAG_KEEP_SCREEN_ON = 128;
    _javaProvider->setWindowFlags(FLAG_KEEP_SCREEN_ON, enable);
}

/**
 * @brief Request write permission for external storage
 * 
 * Requests the WRITE_EXTERNAL_STORAGE permission from the Android system.
 * This triggers the system permission dialog and handles the result.
 * 
 * @return true if permission was successfully added, false otherwise
 * 
 * @note This uses JNI to call addPermision on the Java side
 * @note The permission must be declared in AndroidManifest.xml
 */
bool AndroidPlatformTools::getAccessToWriteInStorage() {
    return _javaProvider->addPermision("android.permission.WRITE_EXTERNAL_STORAGE");
}

/**
 * @brief Request read permission for external storage
 * 
 * Requests the READ_EXTERNAL_STORAGE permission from the Android system.
 * This triggers the system permission dialog and handles the result.
 * 
 * @return true if permission was successfully added, false otherwise
 * 
 * @note This uses JNI to call addPermision on the Java side
 */
bool AndroidPlatformTools::getAccessToReadInStorage() {
    return _javaProvider->addPermision("android.permission.READ_EXTERNAL_STORAGE");

}

}

#endif
