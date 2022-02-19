//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#include "iplatformtools.h"

#include <androidplatformtools.h>
#include <linuxdesktopplatfomtools.h>
#include <windowsdesktopplatformtool.h>
#include <osxplatformtools.h>
#include <iosplatformtools.h>


namespace Platforms {

IPlatformTools *IPlatformTools::instance() {
    static IPlatformTools * instance = new LinuxDesktopPlatfomTools();

#ifdef Q_OS_LINUX
#ifdef Q_OS_ANDROID
    static IPlatformTools * instance = new AndroidPlatformTools();
#else

#endif
#endif

#ifdef Q_OS_WINDOWS
    static IPlatformTools * instance = new WindowsDesktopPlatformTool();
#endif

#ifdef Q_OS_MACOS
    static IPlatformTools * instance = new OSXPlatformTools();
#endif

#ifdef Q_OS_IOS
    static IPlatformTools * instance = new IOSPlatformTools();
#endif

    return instance;
}

}
