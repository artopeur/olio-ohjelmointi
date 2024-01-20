#include "kerrostalo.h"
#include <iostream>

using namespace std;

kerrostalo::kerrostalo() {
    cout<< "Kerrostalo luotu."<<endl;
}

double kerrostalo::laskeKulutus(double sum) {
    double retVal=(eka.laskeKulutus(sum)+toka.laskeKulutus(sum)+kolmas.laskeKulutus(sum));
    return retVal;
}
