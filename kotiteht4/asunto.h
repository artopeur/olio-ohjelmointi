#ifndef ASUNTO_H
#define ASUNTO_H

class Asunto
{
public:
    Asunto();
    ~Asunto();
    int asukasMaara=2;
    int neliot = 100;
    void maarita(int,int);
    double laskekulutus(double);
};
#endif // ASUNTO_H
