#include "asunto.h"
#include <iostream>

using namespace std;

Asunto::Asunto() {
    cout<< "asunto luotu"<<endl;;
    //maarita(2,100);
}
Asunto::~Asunto(){

}

void Asunto::maarita(int asukkaat, int ne) {
    neliot=ne;
    asukasMaara = asukkaat;
    cout<<"Asunto maaritetty asukkaita= " <<asukasMaara;
    cout<<" nelioita= "<<neliot<<endl;
}

double Asunto::laskekulutus(double sum) {
    double retSum=sum*asukasMaara*neliot;
    //cout<< "asunnon kulutus, kun hinta="<<sum;
    //cout<< " on "<<retSum<<endl;
    return retSum;

}
