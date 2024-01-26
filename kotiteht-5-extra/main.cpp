#include <iostream>
#include <stdlib.h>
//#include "devicemouse.h"
//#include "devicedisplay.h"
//#include "devicetouchpad.h"
#include "mydeviceui.h"

using namespace std;

int main()
{
    short choise = 0;
    bool running = true;
    MyDeviceUI ui;
    while (running) {

        while (choise == 0)  {
            ui.uiShowMenu();
            cin>>choise;
            system("CLS");
        }
        switch (choise) {
        case 1:
            cout<<"chose 1."<<endl;
            ui.uiSetMouseInformation();
            choise=0;
            break;
        case 2:
            cout<<"chose 2."<<endl;
            ui.uiSetTouchPadInformation();
            choise=0;
            break;
        case 3:
            cout<<"chose 3."<<endl;
            ui.uiSetDisplayInformation();
            choise=0;
            break;
        case 4:
            cout<<"chose 4."<<endl;
            ui.uiShowDeviceInformation();
            choise=0;
            break;
        case 5:
            cout<<"ending program."<<endl;
            running=false;
            break;
        default:
            cout<<"Invalid input. Give input between 1 and 5"<<endl;
            choise=0;
            break;
        }

    }


/*
    DeviceMouse a;
    DeviceDisplay b;
    DeviceTouchPad c;

    a.setDeviceID();
    a.setPrimaryButton();

    b.setDeviceID();
    b.setDisplayResolution();

    c.setDeviceID();
    c.setTouchPadSensitivity();

    cout<<"Value inputs were: "<<endl<<endl;
    cout<<"\nMouse:"<<endl<<endl;
    a.getDeviceID();
    a.getPrimaryButton();
    cout<<"\nDisplay:"<<endl<<endl;
    b.getDeviceID();
    b.getDisplayResolution();

    cout<<"\nTouchpad:"<<endl<<endl;
    c.getDeviceID();
    c.getTouchpadSensitivity();
    cout<<"\n"<<endl;
*/
return 0;
}
