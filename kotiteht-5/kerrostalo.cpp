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

}
