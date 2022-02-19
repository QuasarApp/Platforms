//#
//# Copyright (C) 2021-2022 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "Platforms/global.h"
#include <QString>

inline void initPlatformsResources() { Q_INIT_RESOURCE(Platforms); }

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
