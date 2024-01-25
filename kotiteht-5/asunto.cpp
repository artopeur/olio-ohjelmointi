#include "asunto.h"

asunto::asunto() {
    cout<< "asunto luotu"<<endl;;
    //maarita(2,100);
}
asunto::~asunto(){
    cout<< "asunto tuhottu"<<endl;
}

void asunto::maarita(int asukkaat, int ne) {
    neliot=ne;
    asukasMaara = asukkaat;
    cout<<"Asunto maaritetty asukkaita= " <<asukasMaara;
    cout<<" nelioita= "<<neliot<<endl;
}

double asunto::laskekulutus(double sum) {
    double retSum=sum*asukasMaara*neliot;
    //cout<< "asunnon kulutus, kun hinta="<<sum;
    //cout<< " on "<<retSum<<endl;
    return retSum;

}
