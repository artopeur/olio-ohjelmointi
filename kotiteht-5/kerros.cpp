#include "kerros.h"
#include "asunto.h"

kerros::kerros() {
    cout<<"Kerros luotu:"<<endl;

    as1 = new asunto();
    as2 = new asunto();
    as3 = new asunto();
    as4 = new asunto();

    //kerros::maaritaAsunnot();
}

kerros::~kerros() {
    delete as1;
    delete as2;
    delete as3;
    delete as4;
    cout<<"kerros tuhottu: "<<endl;
}

void kerros::maaritaAsunnot() {
    cout<<"Maaritetaan 4 kpl asuntoja."<<endl;
    as1->maarita(2,100);
    as2->maarita(2,100);
    as3->maarita(2,100);
    as4->maarita(2,100);
}

double kerros::laskeKulutus(double a) {
    double sum=0.00;
    sum=as1->laskekulutus(a);
    sum+=as2->laskekulutus(a);
    sum+=as3->laskekulutus(a);
    sum+=as4->laskekulutus(a);

    return sum;
}
