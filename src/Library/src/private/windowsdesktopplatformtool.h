//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef WINDOWSDESKTOPPLATFORMTOOL_H
#define WINDOWSDESKTOPPLATFORMTOOL_H
#include <Platforms/iplatformtools.h>

#ifdef Q_OS_WINDOWS

namespace Platforms {

/**
 * @class WindowsDesktopPlatformTool
 * @brief Windows desktop implementation of IPlatformTools
 * 
 * This class provides Windows desktop platform utilities including:
 * - Screen dimming control (not fully supported)
 * - Storage access (not fully supported)
 * 
 * @note This class inherits from IPlatformTools and implements all required methods.
 * @note Methods may have limited functionality on Windows
 * @note Requires Q_OS_WINDOWS preprocessor condition to be defined
 * 
 * @since 3.0.0
 */
class WindowsDesktopPlatformTool : public IPlatformTools
{
public:
    /**
     * @brief Constructor
     * 
     * Initializes the Windows desktop platform tools.
     */
    WindowsDesktopPlatformTool();

    /**
     * @brief Set screen dim mode on Windows
     * 
     * Controls screen dimming on Windows.
     * This is a platform-specific implementation.
     * 
     * @param enable true to prevent screen dimming, false to allow dimming
     */
    void setScreanDim(bool enable) const override;

    /**
     * @brief Request write access to external storage on Windows
     * 
     * Requests permission for writing to external storage on Windows.
     * 
     * @return true if access granted, false otherwise
     */
    bool getAccessToWriteInStorage() override;

    /**
     * @brief Request read access to external storage on Windows
     * 
     * Requests permission for reading from external storage on Windows.
     * 
     * @return true if access granted, false otherwise
     */
    bool getAccessToReadInStorage() override;

};

}

#endif

#endif // WINDOWSDESKTOPPLATFORMTOOL_H
