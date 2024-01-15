#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game(int);
    ~Game(void);
    void Play(void);
private:
    int maxNumber=0;
    int playerGuess=0;
    int randomNumber=0;
    int numberOfGuesses=0;
    void printGameResult(void);
protected:

};

#endif // GAME_H
