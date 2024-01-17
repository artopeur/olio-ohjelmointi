#include "chef.h"
#include <iostream>
using namespace std;

Chef::Chef() {
    // ei tule nimeä kun käytetään italianChef kutsua kontruktorille.
    //cout<<"Chef "<<name<<" konstruktori"<<endl;
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
    cout<< "Chef " << name << " konstruktori" << endl;

}
italianChef::~italianChef() {
    cout<<"Chef "<<name<<" destruktori"<<endl;
}

string italianChef::getName() {
    return name;
}
