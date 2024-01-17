#include <iostream>
#include "chef.h"
using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    Chef Gordon("Gordon Ramsay");
    Gordon.makeSalad();
    Gordon.makeSoup();
    Chef Anthony("Anthony Bourdain");
    Anthony.makeSalad();
    Anthony.makeSoup();
    return 0;
}
