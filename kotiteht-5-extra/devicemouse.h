#ifndef DEVICEMOUSE_H
#define DEVICEMOUSE_H
#include "devicebaseclass.h"

class DeviceMouse : public DeviceBaseClass
{
public:
    DeviceMouse();
    void setPrimaryButton();
    short getPrimaryButton();

protected:


private:

    short primaryButton;
};

#endif // DEVICEMOUSE_H
