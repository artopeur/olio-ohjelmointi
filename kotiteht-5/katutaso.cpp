#include "katutaso.h"
#include <iostream>

using namespace std;

katutaso::katutaso() {
    cout<< "Katutaso luotu:"<<endl;
    as1 = new asunto;
    as2 = new asunto;
    //katutaso::maaritaAsunnot();
}
katutaso::~katutaso() {
    delete as1;
    delete as2;
    cout<<"katutaso tuhottu:"<<endl;
}

void katutaso::maaritaAsunnot() {
    cout<<"Maaritetaan 2 klp asuntoja."<<endl;
    as1->maarita(2,100);
    as2->maarita(2,100);
}

double katutaso::laskeKulutus(double a)
{
    double sum=0.00;
    sum=as1->laskekulutus(a);
    sum+=as2->laskekulutus(a);
    return sum;
}
