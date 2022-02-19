#ifndef OSXPLATFORMTOOLS_H
#define OSXPLATFORMTOOLS_H
#include <Platforms/iplatformtools.h>

namespace Platforms {

class OSXPlatformTools: public IPlatformTools
{

public:
    void setScreanDim(bool enable) const override;
    bool getAccessToWriteInStorage() override;
    bool getAccessToReadInStorage() override;
protected:
    OSXPlatformTools();

    // IPlatformTools interface

    friend class IPlatformTools;
;

};
}
#endif // OSXPLATFORMTOOLS_H
