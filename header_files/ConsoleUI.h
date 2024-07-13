#ifndef ConsoleUI_H
#define ConsoleUI_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Console{
  public:
    void displayDice(vector<int> diceValues)const;
    vector<int> getRerollIndices()const;
    void welcomeMessage();
    bool askReroll();
};










#endif