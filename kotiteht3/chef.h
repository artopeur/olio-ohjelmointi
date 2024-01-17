#ifndef CHEF_H
#define CHEF_H
#include<iostream>
using namespace std;

class Chef
{
public:
    Chef();
    Chef(string);
    virtual ~Chef();
    string name="";
    void makeSalad();
    void makeSoup();
};

class italianChef : public Chef
{
public:
    italianChef();
    italianChef(string);
    virtual ~italianChef();
    void makePasta();
    string getName();
};

#endif // CHEF_H
