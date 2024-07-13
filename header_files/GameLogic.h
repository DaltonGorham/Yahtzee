#ifndef GameLogic_H
#define GameLogic_H
#include "Die.h"
#include <vector>

class Game{
  private: 
    vector<Die> dice;
  public:
    Game() : dice(5) {};
    vector<int> getDiceValues()const;
    vector<int> calculateScores()const;
    void rollAllDice();
    void rerollDice(vector<int> indices);
};





#endif