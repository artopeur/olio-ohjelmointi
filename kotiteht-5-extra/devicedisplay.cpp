#include "devicedisplay.h"

DeviceDisplay::DeviceDisplay() {
    cout<<"Display constructor"<<endl;
}

void DeviceDisplay::setDisplayResolution() {
    cout << "Give display resolution: ";
    cin >> DisplayResolution;
}

short DeviceDisplay::getDisplayResolution() {
    cout << "Display Resolution: "<<DisplayResolution<<endl;
    return DisplayResolution;
}
