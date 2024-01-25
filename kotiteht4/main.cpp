#include <iostream>
#include "kerrostalo.h"


using namespace std;

int main()
{
    //cout << "Hello World!" << endl;

    kerrostalo ekaKerrostalo;
    double test=ekaKerrostalo.laskeKulutus(1.00);
    cout<<endl<<"Kokonaiskulutus: "<<test<<endl<<endl;

    //kerros toka;
    //eka.maaritaAsunnot();
    //toka.maaritaAsunnot();

    // testataan refas1


    cout << "Kulutus referenssissa: " << ekaKerrostalo.refas.laskeKulutus(1) << endl << endl;

    return 0;
}
