#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void startGame(void);

int main()
{
    // need to make this seed random too, so that the number will not always be the same.


    cout << "Hello World!" << endl;
    cout << "\nAnother Day!" << endl;

    startGame();


    return 0;
}

void startGame() {
    // current time to choose a srand value
    srand(time(0));
    //for loop for value searching.
    int arvottuluku = rand() % 20;
    //cout << "arvottu luku: " << arvottuluku << endl;
    cout<<"Try to guess value between 1-19"<<endl;
    int arvaus=0;
    while(arvaus != arvottuluku) {
        cout<<"Gues number:"<<endl;
        cin>>arvaus;
        if(arvaus > arvottuluku) {
            cout<<"Your gues was too large, try again."<<endl;
        }
        else if(arvaus < arvottuluku) {
            cout<<"Your guess was too small, try again."<<endl;
        }

    }
    cout<<"On the money, good job!"<<endl;
}
