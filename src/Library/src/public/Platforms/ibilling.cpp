//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "ibilling.h"
#include <androidbilling.h>

namespace Platforms {

IBilling::IBilling() {
    qRegisterMetaType<Platforms::Purchase>();
}

IBilling *IBilling::instance() {
    static IBilling * instance = nullptr;

#ifdef Q_OS_LINUX
#ifdef Q_OS_ANDROID
    instance = new AndroidBilling();
#else
#endif
#endif

#ifdef Q_OS_WINDOWS
#endif

#ifdef Q_OS_MACOS
#endif

#ifdef Q_OS_IOS
#endif

    return instance;
}

}
