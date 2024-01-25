#include "katutaso.h"
//#include "asunto.h"
#include <iostream>

using namespace std;

Katutaso::Katutaso() {
    cout<< "katutaso luotu"<<endl;
    Katutaso::maaritaAsunnot();
}

Katutaso::~Katutaso()
{

}

void Katutaso::maaritaAsunnot()
{
    //Asunto as1;       // ei tarvita tässä enää, kun määrittely on tehty .h tiedostossa
    as1.maarita(as1.asukasMaara,as1.neliot);
    //Asunto as2;       // ei tarvita tässä enää, kun määrittely on tehty .h tiedostossa
    as2.maarita(as2.asukasMaara, as2.neliot);
}
double Katutaso::laskeKulutus(double sum) {
    double retVal=0.00;
    retVal=(as1.laskekulutus(sum)+as2.laskekulutus(sum));
    //retVal=150.1;

    return retVal;
}
