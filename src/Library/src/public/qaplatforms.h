//#
//# Copyright (C) 2021-2022 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "Platforms/global.h"
#include <QString>
#include "Platforms/ibilling.h"
#include "Platforms/iplatformtools.h"

inline void initPlatformsResources() { Q_INIT_RESOURCE(Platforms); }

/**
 * @brief Platforms This namespace contains classes that help work with different platforms.
 * See IBilling and IPlatformTools interfaces.
 *
 *
 */
namespace Platforms {

/**
 * @brief init main initialize method of The Platforms library
 * @return true if library initialized successfull
 */
bool PLATFORMS_EXPORT init();

/**
 * @brief version This method return string value of a library version
 * @return string value of a library version
 */
QString PLATFORMS_EXPORT version();

};
