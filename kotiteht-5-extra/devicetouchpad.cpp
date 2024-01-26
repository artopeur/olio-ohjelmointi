#include "devicetouchpad.h"

DeviceTouchPad::DeviceTouchPad() {

}

void DeviceTouchPad::setTouchPadSensitivity() {
    cout<<"set Touchpad sensitivity: ";
    cin>>touchSensitivity;

}

short DeviceTouchPad::getTouchpadSensitivity() {
    cout<<"touchSensitivity is: "<< touchSensitivity<<endl;
    return touchSensitivity;
}
