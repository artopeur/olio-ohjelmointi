#include "kerros.h"
//#include "asunto.h"
#include <iostream>
using namespace std;
kerros::kerros() {
    maaritaAsunnot();
    cout<<"Kerros luotu:"<<endl;
}

void kerros::maaritaAsunnot()
{
    cout<<"Maaritetaan 4kpl asuntoja."<<endl;
    //Asunto As1;   // ei tarvita tässä enää, kun määrittely on tehty .h tiedostossa
    as1.maarita(as1.asukasMaara,as1.neliot);
    //Asunto As2;   // ei tarvita tässä enää, kun määrittely on tehty .h tiedostossa
    as2.maarita(as2.asukasMaara,as2.neliot);
    //Asunto As3;   // ei tarvita tässä enää, kun määrittely on tehty .h tiedostossa
    as3.maarita(as3.asukasMaara,as3.neliot);
    //Asunto As4;   // ei tarvita tässä enää, kun määrittely on tehty .h tiedostossa
    as4.maarita(as4.asukasMaara,as4.neliot);
}

double kerros::laskeKulutus(double sum)
{
    //cout<<"Maaritetaan 2kpl katutason asuntoja."<<endl;
    double retVal=0.00;
    retVal=(as1.laskekulutus(sum)+as2.laskekulutus(sum)+as3.laskekulutus(sum)+as3.laskekulutus(sum));
    //retVal=150.1;

    return retVal;

}
