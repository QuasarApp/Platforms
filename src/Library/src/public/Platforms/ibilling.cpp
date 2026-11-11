//
// Copyright (C) 2027 QuasarApp.
// Distributed under the GPLv3 software license, see the accompanying
// Everyone is permitted to copy and distribute verbatim copies
// of this license document, but changing it is not allowed.
//

#include "ibilling.h"
#include <androidbilling.h>

namespace Platforms {

/**
 * @brief Default constructor for IBilling
 * 
 * Registers the Purchase type for QVariant usage.
 * Platform-specific instance initialization happens in the static instance() method.
 */
IBilling::IBilling() {
    qRegisterMetaType<Platforms::Purchase>();
}

/**
 * @brief Get the billing instance for current platform
 * 
 * This static method returns a platform-specific billing implementation.
 * It uses a singleton pattern to ensure only one instance exists per platform.
 * 
 * @return Pointer to the billing instance, or nullptr if platform not supported
 * 
 * @note The method initializes platform-specific billing on first call
 * @note Returns nullptr for unsupported platforms (Linux, Windows, macOS without billing)
 * 
 * Platform support:
 * - Android: Returns AndroidBilling instance
 * - iOS: Returns platform-specific iOS billing
 * - Others: Returns nullptr
 */
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
