#ifndef KERROSTALO_H
#define KERROSTALO_H
#include "katutaso.h"
#include "kerros.h"

class kerrostalo
{
public:
    kerrostalo();
    double laskeKulutus(double);
    Katutaso & refas= eka;     // ei käytetä tässä koodissa mihinkään. Testausta varten luotu.
private:
    Katutaso eka;
    kerros toka;
    kerros kolmas;

};

#endif // KERROSTALO_H
