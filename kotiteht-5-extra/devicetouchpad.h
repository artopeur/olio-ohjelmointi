#ifndef DEVICETOUCHPAD_H
#define DEVICETOUCHPAD_H
#include "devicebaseclass.h"

class DeviceTouchPad : public DeviceBaseClass
{
public:
    DeviceTouchPad();
    void setTouchPadSensitivity();
    short getTouchpadSensitivity();
protected:

private:
    short touchSensitivity;
};

#endif // DEVICETOUCHPAD_H
