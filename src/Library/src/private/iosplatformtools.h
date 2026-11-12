//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef IOSPLATFORMTOOLS_H
#define IOSPLATFORMTOOLS_H
#include <Platforms/iplatformtools.h>

namespace Platforms {

/**
 * @class IOSPlatformTools
 * @brief iOS-specific implementation of IPlatformTools
 * 
 * This class provides iOS-specific platform utilities including:
 * - Screen dimming control
 * - External storage access management
 * - iOS-specific system operations
 * 
 * @note This class inherits from IPlatformTools and implements all required methods.
 * @note Requires Q_OS_IOS preprocessor condition to be defined.
 * @note Uses iOS-specific APIs for platform functionality.
 * 
 * @since 3.0.0
 */
class IOSPlatformTools : public IPlatformTools
{
public:
    /**
     * @brief Set screen dim mode for iOS
     * 
     * Controls screen dimming on iOS devices.
     * This is a platform-specific implementation.
     * 
     * @param enable true to prevent screen dimming, false to allow dimming
     */
    void setScreanDim(bool enable) const override;

    /**
     * @brief Request write access to external storage
     * 
     * Requests permission for writing to external storage on iOS.
     * 
     * @return true if access granted, false otherwise
     */
    bool getAccessToWriteInStorage() override;

    /**
     * @brief Request read access to external storage
     * 
     * Requests permission for reading from external storage on iOS.
     * 
     * @return true if access granted, false otherwise
     */
    bool getAccessToReadInStorage() override;

protected:
    /**
     * @brief Protected constructor
     * 
     * Initializes the iOS platform tools.
     */
    IOSPlatformTools();

    /**
     * @brief Friend declaration
     * 
     * Allows IPlatformTools to access protected members.
     */
    friend class IPlatformTools;

};

}

#endif // IOSPLATFORMTOOLS_H
