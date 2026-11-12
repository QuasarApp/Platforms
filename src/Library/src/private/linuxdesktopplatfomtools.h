//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#ifndef LINUXDESKTOPPLATFOMTOOLS_H
#define LINUXDESKTOPPLATFOMTOOLS_H
#include <Platforms/iplatformtools.h>

namespace Platforms {

/**
 * @class LinuxDesktopPlatfomTools
 * @brief Linux desktop implementation of IPlatformTools
 * 
 * This class provides Linux desktop platform utilities including:
 * - Screen dimming control (not supported on Linux)
 * - Storage access (not supported on Linux)
 * 
 * @note This class inherits from IPlatformTools and implements all required methods.
 * @note Methods return false for operations that are not supported on Linux
 * @note This is the default implementation when no specific platform is detected
 * 
 * @since 3.0.0
 */
class LinuxDesktopPlatfomTools : public IPlatformTools
{

public:
    /**
     * @brief Set screen dim mode (not supported on Linux)
     * 
     * Screen dimming is not supported on Linux desktop.
     * This method does nothing and returns true.
     * 
     * @param enable Parameter is ignored
     */
    void setScreanDim(bool enable) const override;

    /**
     * @brief Request write access to external storage (not supported)
     * 
     * External storage access is not supported on Linux desktop.
     * This method returns true as a placeholder.
     * 
     * @return true (placeholder)
     */
    bool getAccessToWriteInStorage() override;

    /**
     * @brief Request read access to external storage (not supported)
     * 
     * External storage access is not supported on Linux desktop.
     * This method returns true as a placeholder.
     * 
     * @return true (placeholder)
     */
    bool getAccessToReadInStorage() override;

protected:
    /**
     * @brief Protected constructor
     * 
     * Initializes the Linux desktop platform tools.
     */
    LinuxDesktopPlatfomTools();

    /**
     * @brief Friend declaration
     * 
     * Allows IPlatformTools to access protected members.
     */

    friend class IPlatformTools;
};

}

#endif // LINUXDESKTOPPLATFOMTOOLS_H
