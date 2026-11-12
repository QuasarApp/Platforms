//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "linuxdesktopplatfomtools.h"

namespace Platforms {

/**
 * @brief Constructor for LinuxDesktopPlatfomTools
 * 
 * Initializes the Linux desktop platform tools.
 * This is a protected constructor used by the singleton pattern.
 */
LinuxDesktopPlatfomTools::LinuxDesktopPlatfomTools()
{

}

/**
 * @brief Set screen dim mode on Linux
 * 
 * Screen dimming is not supported on Linux desktop.
 * This method does nothing.
 * 
 * @param enable Parameter is ignored
 * 
 * @note This is a placeholder - Linux doesn't support screen dimming
 */
void LinuxDesktopPlatfomTools::setScreanDim(bool ) const {
    // TO-DO
}

/**
 * @brief Request write access to external storage on Linux
 * 
 * External storage access is not supported on Linux desktop.
 * This method returns true as a placeholder.
 * 
 * @return true (placeholder - no actual implementation)
 */
bool LinuxDesktopPlatfomTools::getAccessToWriteInStorage() {
    // do nothing
    return true;
}

/**
 * @brief Request read access to external storage on Linux
 * 
 * External storage access is not supported on Linux desktop.
 * This method returns true as a placeholder.
 * 
 * @return true (placeholder - no actual implementation)
 */
bool LinuxDesktopPlatfomTools::getAccessToReadInStorage() {
    // do nothing
    return true;

}

}
