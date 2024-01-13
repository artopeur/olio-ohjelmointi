#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
using namespace std;

Game::Game(int number)
{
    Game::maxNumber = number;
    cout<<"GAME CONSTRUCTOR: Object initiated with"<< maxNumber<<endl;
}
Game::~Game()
{
    cout<<"GAME DESTRUCTOR: object cleared from stack memory."<<endl;;
}
void Game::Play()
{
    cout<<"Beginning game:"<<endl;
    srand(time(0));
    //int arvottuluku = rand() % numberInput+1;
    //cout << "arvottu luku: " << arvottuluku << endl;

    randomNumber = rand() % (maxNumber) + 1;
    cout<<"Try to guess value between 1-"<<maxNumber<<endl;
    //int arvaus=0;
    //int counter=0;
    while(playerGuess != randomNumber) {
        cout<<"Gues number:"<<endl;
        cin>>playerGuess;
        numberOfGuesses++;
        if(playerGuess > randomNumber) {
            cout<<"Your gues was too large, try again."<<endl;
        }
        else if(playerGuess < randomNumber) {
            cout<<"Your guess was too small, try again."<<endl;
        }
    }
    printGameResult();
}

void Game::printGameResult() {
    cout<<"On the money, good job!"<<endl;
    cout<<"you tried to find the number "<<numberOfGuesses<< " times."<<endl;

}
