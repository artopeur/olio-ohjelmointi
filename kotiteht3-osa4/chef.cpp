#include "chef.h"
#include <iostream>
using namespace std;

Chef::Chef() {
    // ei tule nimeä kun käytetään italianChef kutsua kontruktorille.
    //cout<<"Chef "<<name<<" konstruktori"<<endl;
    //name=italianChef().getName();
}

Chef::Chef(string a) {
    name=a;
    cout<<"Chef "<<a<<" konstruktori"<<endl;
}
Chef::~Chef() {
    cout<<"Chef "<<name<<" destruktori"<<endl;
}
void Chef::makeSoup() {
    cout<<"Chef "<<name<<" makes soup"<<endl;
}
void Chef::makeSalad() {
    cout<<"Chef "<<name<<" makes salad"<<endl;
}
italianChef::italianChef(string b) {
    name=b;
    cout<< "italianChef " << name << " konstruktori" << endl;

}
italianChef::~italianChef() {
    cout<<"italianChef "<<name<<" destruktori"<<endl;
}

string italianChef::getName() {
    return name;
}

void italianChef::makePasta(int a, int b) {
    jauhot = a;
    vesi=b;
    cout<< "Chef "<< name << " makes pasta with special recipe"<<endl;
    cout<< "Chef "<< name << " uses Jauhot = " << jauhot<<endl;
    cout<<"Chef " << name << " uses vesi = " << vesi<<endl;
}
