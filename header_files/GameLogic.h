#ifndef GameLogic_H
#define GameLogic_H
#include "Die.h"
#include <vector>

class Game{
  private: 
    vector<Die> dice; 
    int roll;
  public:
    Game(); // Constructor to initialize the game with a certain number of dice
    vector<int> getDiceValues()const;
    vector<int> calculateScores()const;
    void setRoll(int index);
    int getRoll()const;
    void rollAllDice();
    void rerollDice(vector<int> indices);
};





#endif