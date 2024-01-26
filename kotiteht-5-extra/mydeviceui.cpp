#include "mydeviceui.h"

MyDeviceUI::MyDeviceUI() {
    ObjectDeviceMouse = new DeviceMouse;
    ObjectDeviceTouchpad = new DeviceTouchPad;
    ObjectDeviceDisplay = new DeviceDisplay;
}
MyDeviceUI::~MyDeviceUI() {
    delete ObjectDeviceMouse;
    delete ObjectDeviceTouchpad;
    delete ObjectDeviceDisplay;
}
void MyDeviceUI::uiShowMenu()
{
        cout<<"DEVICE MENU\n====================\n"<<endl;
        cout<<"1: Set Mouse Information"<<endl;
        cout<<"2: Set Touch Pad Information"<<endl;
        cout<<"3: Set Display Information"<<endl;
        cout<<"4: Show Devices Information"<<endl;
        cout<<"5: Finish"<<endl;

        cout<<"=> ";
}

void MyDeviceUI::uiSetMouseInformation()
{
    cout<<"MOUSE MENU\n============="<<endl;
    ObjectDeviceMouse->setDeviceID();
    ObjectDeviceMouse->setPrimaryButton();
    //cout<<"=> ";
}

void MyDeviceUI::uiSetTouchPadInformation()
{
    ObjectDeviceTouchpad->setDeviceID();
    ObjectDeviceTouchpad->setTouchPadSensitivity();
    //cout<<"=> ";
}

void MyDeviceUI::uiSetDisplayInformation()
{
    ObjectDeviceDisplay->setDeviceID();
    ObjectDeviceDisplay->setDisplayResolution();
    //cout<<"=> ";
}

void MyDeviceUI::uiShowDeviceInformation()
{
    ObjectDeviceMouse->getDeviceID();
    ObjectDeviceMouse->getPrimaryButton();

    ObjectDeviceTouchpad->getDeviceID();
    ObjectDeviceTouchpad->getTouchpadSensitivity();

    ObjectDeviceDisplay->getDeviceID();
    ObjectDeviceDisplay->getDisplayResolution();

    //cout<<"=> ";
}
