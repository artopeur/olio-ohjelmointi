#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int startGame(int);

int main()
{
    // need to make this seed random too, so that the number will not always be the same.


    cout << "Hello World!" << endl;
    cout << "\nAnother Day!" << endl;
    int howBig=0;
    cout << "Anna suurin arvottava luku: ";
    cin >> howBig;
    int numberOfTries=0;
    numberOfTries=startGame(howBig);

    cout<<"\n\nYou tried to guess the value " <<numberOfTries<<" times."<<endl;

    return 0;
}

int startGame(int numberInput) {
    // current time to choose a srand value
    srand(time(0));
    //for loop for value searching.
    int arvottuluku = rand() % numberInput+1;
    //cout << "arvottu luku: " << arvottuluku << endl;
    cout<<"Try to guess value between 1-"<<numberInput<<endl;
    int arvaus=0;
    int counter=0;
    while(arvaus != arvottuluku) {
        cout<<"Gues number:"<<endl;
        cin>>arvaus;
        counter++;
        if(arvaus > arvottuluku) {
            cout<<"Your gues was too large, try again."<<endl;
        }
        else if(arvaus < arvottuluku) {
            cout<<"Your guess was too small, try again."<<endl;
        }
    }
    cout<<"On the money, good job!"<<endl;
    return counter;
}
