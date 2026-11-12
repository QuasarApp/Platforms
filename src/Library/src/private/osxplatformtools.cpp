//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "osxplatformtools.h"

namespace Platforms {

/**
 * @brief Constructor for OSXPlatformTools
 * 
 * Initializes the macOS platform tools.
 * This is a protected constructor used by the singleton pattern.
 */
OSXPlatformTools::OSXPlatformTools()
{

}

/**
 * @brief Set screen dim mode on macOS
 * 
 * Controls whether the screen should dim on macOS.
 * This is a placeholder implementation marked as TO-DO.
 * 
 * @param enable true to prevent screen dimming, false to allow dimming
 * 
 * @note This method currently does nothing - implementation pending
 * @note Platform-specific macOS APIs need to be implemented
 */
void OSXPlatformTools::setScreanDim(bool ) const {
    // TO-DO
}

/**
 * @brief Request write access to external storage on macOS
 * 
 * Requests permission for writing to external storage on macOS.
 * 
 * @return true (placeholder implementation)
 * 
 * @note This method currently returns true - implementation pending
 * @note Platform-specific macOS APIs need to be implemented
 */
bool OSXPlatformTools::getAccessToWriteInStorage() {
    return true;
}

/**
 * @brief Request read access to external storage on macOS
 * 
 * Requests permission for reading from external storage on macOS.
 * 
 * @return true (placeholder implementation)
 * 
 * @note This method currently returns true - implementation pending
 * @note Platform-specific macOS APIs need to be implemented
 */
bool OSXPlatformTools::getAccessToReadInStorage() {
    return true;
}

}
