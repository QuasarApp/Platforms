//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "iosplatformtools.h"
namespace Platforms {

IOSPlatformTools::IOSPlatformTools()
{

}

void IOSPlatformTools::setScreanDim(bool ) const {
    // TO-DO
}

bool IOSPlatformTools::getAccessToWriteInStorage() {
    return true;
}

bool IOSPlatformTools::getAccessToReadInStorage() {
    return true;
}
}
