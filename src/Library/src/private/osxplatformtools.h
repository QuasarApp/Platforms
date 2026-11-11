//
// Copyright (C) 2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef OSXPLATFORMTOOLS_H
#define OSXPLATFORMTOOLS_H
#include <Platforms/iplatformtools.h>

namespace Platforms {

/**
 * @class OSXPlatformTools
 * @brief macOS-specific implementation of IPlatformTools
 * 
 * This class provides macOS-specific platform utilities including:
 * - Screen dimming control
 * - Storage access management
 * - macOS-specific system operations
 * 
 * @note This class inherits from IPlatformTools and implements all required methods.
 * @note Requires Q_OS_MACOS preprocessor condition to be defined.
 * @note Uses macOS-specific APIs for platform functionality.
 * 
 * @since 3.0.0
 */
class OSXPlatformTools : public IPlatformTools
{
public:
    /**
     * @brief Set screen dim mode for macOS
     * 
     * Controls screen dimming on macOS devices.
     * This is a platform-specific implementation.
     * 
     * @param enable true to prevent screen dimming, false to allow dimming
     */
    void setScreanDim(bool enable) const override;

    /**
     * @brief Request write access to external storage on macOS
     * 
     * Requests permission for writing to external storage on macOS.
     * 
     * @return true if access granted, false otherwise
     */
    bool getAccessToWriteInStorage() override;

    /**
     * @brief Request read access to external storage on macOS
     * 
     * Requests permission for reading from external storage on macOS.
     * 
     * @return true if access granted, false otherwise
     */
    bool getAccessToReadInStorage() override;

protected:
    /**
     * @brief Protected constructor
     * 
     * Initializes the macOS platform tools.
     */
    OSXPlatformTools();

    /**
     * @brief Friend declaration
     * 
     * Allows IPlatformTools to access protected members.
     */
    friend class IPlatformTools;

};

}

#endif // OSXPLATFORMTOOLS_H
