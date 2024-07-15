#ifndef GameLogic_H
#define GameLogic_H
#include "Die.h"
#include <iostream>
#include <vector>

class Game{
  private: 
    vector<Die> dice; 
    int roll;
    vector<int> upperScores;
    vector<int> lowerScores;
    int round;
  public:
    Game(); // Constructor to initialize the game with a certain number of dice
    vector<int> getDiceValues()const;
    vector<int> getRerollIndices()const;
    vector<int> calculateScores()const;
    vector<int> getUpperScores()const;
    vector<int> getLowerScores()const;
    void setRoll(int index);
    int getRoll()const;
    void rollAllDice();
    void rerollDice(vector<int> indices);
    void updateScore(int category, int points);
    int getRound();
    void setRound(int r);
};





#endif