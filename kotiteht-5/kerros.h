#ifndef KERROS_H
#define KERROS_H
#include "asunto.h"

class kerros : public asunto
{
public:
    kerros();
    virtual ~kerros();

    virtual void maaritaAsunnot();
    double laskeKulutus(double);

    asunto * as1;
    asunto * as2;
    asunto * as3;
    asunto * as4;


};

#endif // KERROS_H
