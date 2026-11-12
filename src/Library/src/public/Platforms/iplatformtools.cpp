//
// 2021-2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "iplatformtools.h"
#include <androidplatformtools.h>
#include <linuxdesktopplatfomtools.h>
#include <windowsdesktopplatformtool.h>
#include <osxplatformtools.h>
#include <iosplatformtools.h>

namespace Platforms {

/**
 * @brief Get the platform tools instance
 * 
 * This static method returns a pointer to the platform-specific tools instance.
 * It uses a singleton pattern to ensure only one instance exists per platform.
 * The instance is lazily initialized based on the current platform.
 * 
 * @return Pointer to IPlatformTools implementation for current platform
 * 
 * Platform mapping:
 * - Linux + Android: AndroidPlatformTools
 * - Linux (desktop): LinuxDesktopPlatfomTools
 * - Windows: WindowsDesktopPlatformTool
 * - macOS: OSXPlatformTools
 * - iOS: IOSPlatformTools
 * - Others: LinuxDesktopPlatfomTools (default)
 */
IPlatformTools *IPlatformTools::instance() {
    static IPlatformTools * instance = new LinuxDesktopPlatfomTools();

#ifdef Q_OS_LINUX
#ifdef Q_OS_ANDROID
    instance = new AndroidPlatformTools();
#else

#endif
#endif

#ifdef Q_OS_WINDOWS
    instance = new WindowsDesktopPlatformTool();
#endif

#ifdef Q_OS_MACOS
    instance = new OSXPlatformTools();
#endif

#ifdef Q_OS_IOS
    instance = new IOSPlatformTools();
#endif

    return instance;
}

}
