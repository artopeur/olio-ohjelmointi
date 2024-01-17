#ifndef CHEF_H
#define CHEF_H
#include<iostream>
using namespace std;

class Chef
{
public:
    Chef(string);
    ~Chef();
    string name="";
    void makeSalad();
    void makeSoup();
};

class italianChef : public Chef
{
public:
    italianChef(string);
    ~italianChef();
    void makePasta();
};

#endif // CHEF_H
