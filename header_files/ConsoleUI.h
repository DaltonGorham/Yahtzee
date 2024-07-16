#ifndef ConsoleUI_H
#define ConsoleUI_H
#include "GameLogic.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Console{
  private:
    vector<string> upperSection;
    vector<string> lowerSection;
    Game game;
  public:
    Console(); // Constructor: Initializes Score Card
    void displayDice(vector<int> diceValues)const;
    void welcomeMessage();
    bool askReroll();
    void displayRoll(int index);
    void displayRound(int round);
    void clearScreen();
    void currentDieMessage();
    void displayScoreCard();
    void displayUpdateScoreCard(Game game);
    void displayDieSelection();
    void displayInvalidDie();
    int scoreSelect();
    void buffer();
    vector<string> getUpperSection();
    vector<string> getLowerSection();
    void displayFinalScore();
};










#endif