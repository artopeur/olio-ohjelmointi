#include "kerrostalo.h"

kerrostalo::kerrostalo() {
    cout<< "Kerrostalo luotu."<<endl;
    eka = new katutaso();
    toka = new kerros();
    kolmas = new kerros();
    //kerrostalo::maaritaAsunnot();

}
kerrostalo::~kerrostalo() {
    cout << "kerrostalo tuhottu."<<endl;
}

void kerrostalo::maaritaAsunnot() {
    eka->maaritaAsunnot();
    toka->maaritaAsunnot();
    kolmas->maaritaAsunnot();
}

double kerrostalo::laskeKulutus(double a) {
    double sum=0.00;
    sum=eka->laskeKulutus(a);
    sum+=toka->laskeKulutus(a);
    sum+=kolmas->laskeKulutus(a);
    return sum;
}
