//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef IPLATFORMTOOLS_H
#define IPLATFORMTOOLS_H

#include <QtGlobal>
#include "Platforms/global.h"

namespace Platforms {


/**
 * @brief The IPlatformTools class contains platform dependet utils.
 */
class PLATFORMS_EXPORT IPlatformTools
{
public:
    virtual ~IPlatformTools() = default;

    /**
     * @brief instance This method return platform's dependet billing object. If this library not support current platform then return nullptr.
     * @return platform's dependet billing object
     * @note If this library not support current platform then return nullptr.
     */
    static IPlatformTools* instance();

    /**
     * @brief setScreanDim disable or enable screan dim
     * @param enable sets to true for enable sceen dim or false for disable.
     */
    virtual void setScreanDim(bool enable) const = 0;

    /**
     * @brief getAccessToWriteInStorage This method try allow access to external storage for write.
     */
    virtual bool getAccessToWriteInStorage() = 0;

    /**
     * @brief getAccessToWriteInStorage This method try allow access to external storage for read.
     */
    virtual bool getAccessToReadInStorage() = 0;

protected:
    IPlatformTools() = default;

};
}
#endif // IPLATFORMTOOLS_H
