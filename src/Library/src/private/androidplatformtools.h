//#
//# Copyright (C) 2021-2021 QuasarApp.
//# Distributed under the GPLv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#ifndef AndroidPlatformTools_H
#define AndroidPlatformTools_H

#include <Platforms/iplatformtools.h>

#ifdef Q_OS_ANDROID

class JavaProvider;


namespace Platforms {
class AndroidPlatformTools: public IPlatformTools
{
    // IPlatformTools interface
public:
    void setScreanDim(bool enable) const override;
    bool getAccessToWriteInStorage() override;
    bool getAccessToReadInStorage() override;

protected:
    AndroidPlatformTools();
    friend class IPlatformTools;

    JavaProvider *_javaProvider = nullptr;


};
}

#endif
#endif // AndroidPlatformTools_H
