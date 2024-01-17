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
    void makePasta(int,int);
    string getName();
private:
    int vesi=0;
    int jauhot=0;
};

#endif // CHEF_H
