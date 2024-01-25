#include "devicemouse.h"

DeviceMouse::DeviceMouse() {
    cout<<"Mouse constructor: "<<endl;
}

void DeviceMouse::setPrimaryButton()
{
    cout<<"Set mouse primaryButton: ";
    cin>>primaryButton;
}

short DeviceMouse::getPrimaryButton()
{
    cout<<"MOUSE primaryButton: "<<primaryButton<<endl;
    return primaryButton;
}
