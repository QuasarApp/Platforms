//
// Copyright (C) 2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "iosplatformtools.h"

namespace Platforms {

/**
 * @brief Constructor for IOSPlatformTools
 * 
 * Initializes the iOS platform tools.
 * This is a protected constructor used by the singleton pattern.
 */
IOSPlatformTools::IOSPlatformTools()
{

}

/**
 * @brief Set screen dim mode on iOS
 * 
 * Controls whether the screen should dim when the app is in background.
 * This is a placeholder implementation marked as TO-DO.
 * 
 * @param enable true to prevent screen dimming, false to allow dimming
 * 
 * @note This method currently does nothing - implementation pending
 * @note Platform-specific iOS APIs need to be implemented
 */
void IOSPlatformTools::setScreanDim(bool ) const {
    // TO-DO
}

/**
 * @brief Request write access to external storage on iOS
 * 
 * Currently returns true as placeholder.
 * 
 * @return true (placeholder implementation)
 * 
 * @note This method currently does nothing - implementation pending
 * @note Platform-specific iOS APIs need to be implemented
 */
bool IOSPlatformTools::getAccessToWriteInStorage() {
    return true;
}

/**
 * @brief Request read access to external storage on iOS
 * 
 * Currently returns true as placeholder.
 * 
 * @return true (placeholder implementation)
 * 
 * @note This method currently does nothing - implementation pending
 * @note Platform-specific iOS APIs need to be implemented
 */
bool IOSPlatformTools::getAccessToReadInStorage() {
    return true;
}

}
