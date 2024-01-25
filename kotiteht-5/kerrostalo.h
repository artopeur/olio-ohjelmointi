#ifndef KERROSTALO_H
#define KERROSTALO_H
#include "katutaso.h"

class kerrostalo: public katutaso
{
public:
    kerrostalo();
    ~kerrostalo();
    void maaritaAsunnot();
    double laskeKulutus(double);



private:
    katutaso * eka;
    kerros * toka;
    kerros * kolmas;
};

#endif // KERROSTALO_H
