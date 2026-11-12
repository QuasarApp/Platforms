/**
 * @file qaplatforms.h
 * @brief Main header for Platforms library - Provides cross-platform utilities
 * 
 * This header file provides the main entry point for the Platforms library,
 * which offers platform-specific utilities for Android, iOS, macOS, Linux, and Windows.
 */

//
// Copyright (C) 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "Platforms/global.h"
#include <QString>
#include "Platforms/ibilling.h"
#include "Platforms/iplatformtools.h"

/**
 * @brief Initialize Platforms resources
 * 
 * This function initializes the Qt resource system for the Platforms library.
 * It should be called once during application startup to ensure all platform-specific
 * resources are loaded properly.
 * 
 * @return true if resources initialized successfully
 */
inline void initPlatformsResources() { Q_INIT_RESOURCE(Platforms); }

/**
 * @namespace Platforms
 * @brief Platform-specific utilities and interfaces
 * 
 * This namespace contains classes and interfaces that provide platform-dependent
 * functionality across different operating systems including:
 * - Android - Mobile platform with billing support
 * - iOS - Apple mobile platform with billing support  
 * - macOS - Apple desktop platform
 * - Linux - Desktop platform
 * - Windows - Desktop platform
 * 
 * Key components:
 * - @c IBilling - Interface for in-app purchases across platforms
 * - @c IPlatformTools - Interface for platform-specific system utilities
 * - Implementation classes for each supported platform
 */

namespace Platforms {

/**
 * @brief Initialize the main Platforms library
 * 
 * This function initializes the Platforms library and its resources.
 * It should be called early in the application lifecycle before using
 * any platform-specific features.
 * 
 * @return true if initialization was successful
 * @note Always call this function before accessing platform services
 */
bool PLATFORMS_EXPORT init();

/**
 * @brief Get the current library version
 * 
 * Returns a string containing the version information of the Platforms library.
 * The version string follows semantic versioning format (e.g., "3.0.0").
 * 
 * @return QString containing the library version
 * @example
 * QString version = Platforms::version();
 * qDebug() << "Platforms version:" << version;
 */
QString PLATFORMS_EXPORT version();

} // namespace Platforms
