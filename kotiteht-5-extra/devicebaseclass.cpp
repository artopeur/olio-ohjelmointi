#include "devicebaseclass.h"

DeviceBaseClass::DeviceBaseClass() {
    cout << "Device Base constructor: "<<endl;
}

DeviceBaseClass::~DeviceBaseClass() {
    cout <<"Device Base destructor:"<<endl;
}

short DeviceBaseClass::getDeviceID() {
    cout<<"Device ID: " <<DeviceID<<endl;
    return DeviceID;
}

void DeviceBaseClass::setDeviceID() {
    cout<<"Give device ID: ";
    cin>>DeviceID;
}
