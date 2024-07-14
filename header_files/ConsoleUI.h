#ifndef ConsoleUI_H
#define ConsoleUI_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Console{
  private:
    vector<string> upperSection;
    vector<string> lowerSection;
  public:
    Console();
    void displayDice(vector<int> diceValues)const;
    vector<int> getRerollIndices()const;
    void welcomeMessage();
    bool askReroll();
    void displayRoll(int index);
    void clearScreen();
    void currentDieMessage();
    void displayScoreCard();
};










#endif