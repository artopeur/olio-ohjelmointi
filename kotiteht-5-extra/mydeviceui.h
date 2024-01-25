#ifndef MYDEVICEUI_H
#define MYDEVICEUI_H
#include "devicedisplay.h"
#include "devicemouse.h"
#include "devicetouchpad.h"

class MyDeviceUI : public DeviceDisplay, public DeviceMouse, public DeviceTouchPad
{
public:
    MyDeviceUI();
    ~MyDeviceUI();

    void uiShowMenu();
    void uiSetMouseInformation();
    void uiSetTouchPadInformation();
    void uiSetDisplayInformation();
    void uiShowDeviceInformation();

private:
    DeviceMouse * ObjectDeviceMouse;
    DeviceTouchPad * ObjectDeviceTouchpad;
    DeviceDisplay * ObjectDeviceDisplay;

};

#endif // MYDEVICEUI_H
