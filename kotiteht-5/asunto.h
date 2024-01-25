#ifndef ASUNTO_H
#define ASUNTO_H
#include <iostream>

using namespace std;

class asunto
{
public:
    asunto();
    ~asunto();

    int asukasMaara=2;
    int neliot = 100;
    void maarita(int,int);
    double laskekulutus(double);
};

#endif // ASUNTO_H
