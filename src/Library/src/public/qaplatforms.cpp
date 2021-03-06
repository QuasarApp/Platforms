//#
//# Copyright (C) 2021-2022 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "qaplatforms.h"


namespace Platforms {

bool init() {
    initPlatformsResources();
    return true;
}

QString version() {
    return PLATFORMS_VERSION;
}


}
