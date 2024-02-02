#include <iostream>
#include "kerrostalo.h"

using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    kerrostalo katu;
    katu.maaritaAsunnot();
    double kulutus= 0.00;
    kulutus=katu.laskeKulutus(1);

    cout<<"Kulutus on: "<<kulutus<<endl;
    //kerros object;
    //katu.maaritaAsunnot();
    //object.maaritaAsunnot();
    return 0;
}
