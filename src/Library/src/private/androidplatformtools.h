//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef AndroidPlatformTools_H
#define AndroidPlatformTools_H

#include <Platforms/iplatformtools.h>

#ifdef Q_OS_ANDROID

// Forward declaration
namespace Platforms {
    class JavaProvider;
}

/**
 * @class AndroidPlatformTools
 * @brief Android-specific implementation of IPlatformTools
 * 
 * This class provides Android-specific platform utilities including:
 * - Screen dimming control via window flags
 * - External storage access permission management
 * - JNI integration with Java layer
 * 
 * @note This class inherits from IPlatformTools and implements all required methods.
 * @note Requires Q_OS_ANDROID preprocessor condition to be defined.
 * @note Uses JavaProvider for JNI interactions with Android Java layer.
 * 
 * @since 3.0.0
 */
class AndroidPlatformTools : public IPlatformTools
{
    // IPlatformTools interface implementation
public:
    /**
     * @brief Set screen dim mode for Android
     * 
     * Controls screen dimming by setting the FLAG_KEEP_SCREEN_ON window flag.
     * This prevents the screen from dimming when the app is in the background.
     * 
     * @param enable true to keep screen on, false to allow dimming
     * 
     * @note This method delegates to JavaProvider for JNI calls
     * @note FLAG_KEEP_SCREEN_ON constant value is 128
     */
    void setScreanDim(bool enable) const override;

    /**
     * @brief Request write access to external storage
     * 
     * Requests permission to write to external storage on Android.
     * This triggers the Android permission dialog and handles the result.
     * 
     * @return true if permission granted, false otherwise
     * 
     * @note This method adds the WRITE_EXTERNAL_STORAGE permission
     * @note Permission must be declared in AndroidManifest.xml
     */
    bool getAccessToWriteInStorage() override;

    /**
     * @brief Request read access to external storage
     * 
     * Requests permission to read from external storage on Android.
     * This triggers the Android permission dialog and handles the result.
     * 
     * @return true if permission granted, false otherwise
     * 
     * @note This method adds the READ_EXTERNAL_STORAGE permission
     */
    bool getAccessToReadInStorage() override;

protected:
    /**
     * @brief Protected constructor
     * 
     * Initializes the AndroidPlatformTools instance and sets up JavaProvider.
     */
    AndroidPlatformTools();

    /**
     * @brief Friend declaration
     * 
     * Allows IPlatformTools to access protected members.
     */
    friend class IPlatformTools;

    /**
     * @brief Java provider for JNI interactions
     * 
     * Pointer to JavaProvider instance used for JNI calls.
     */
    JavaProvider *_javaProvider = nullptr;

};

}

#endif

#endif // AndroidPlatformTools_H
