//
// Copyright (C) 2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "qaplatforms.h"

namespace Platforms {

/**
 * @brief Initialize the Platforms library
 * 
 * This function initializes the Platforms library and loads platform-specific resources.
 * It should be called once at application startup before using any platform services.
 * The function initializes resources for the current platform and prepares the library
 * for use.
 * 
 * @return true if initialization was successful
 * 
 * @note This function is thread-safe and can be called from any thread.
 * @note For detailed initialization status, check platform-specific logs.
 */
bool init() {
    initPlatformsResources();
    return true;
}

/**
 * @brief Get the current library version string
 * 
 * Returns a string containing the version information of the Platforms library.
 * The version follows semantic versioning (MAJOR.MINOR.PATCH) format.
 * 
 * @return QString containing the library version
 * 
 * @example
 * QString ver = Platforms::version();
 * qDebug() << "Platforms version:" << ver;
 * 
 * @since 3.0.0
 */
QString version() {
    return PLATFORMS_VERSION;
}

}
