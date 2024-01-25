#include "devicetouchpad.h"

DeviceTouchPad::DeviceTouchPad() {

}

void DeviceTouchPad::setTouchPadSensitivity() {
    cout<<"set Touchpad sensitivity: "<<endl;
    cin>>touchSensitivity;

}

short DeviceTouchPad::getTouchpadSensitivity() {
    cout<<"touchSensitivity is: "<<endl;
    return touchSensitivity;
}
