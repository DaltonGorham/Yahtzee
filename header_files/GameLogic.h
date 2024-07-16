#ifndef GameLogic_H
#define GameLogic_H
#include "Die.h"
#include <iostream>
#include <vector>


struct ScoringFlags {
    bool pair = false;
    bool threeInARow = false;
    bool fourInARow = false;
    bool Yahtzee = false;
    bool smallStraight = false;
    bool largeStraight = false;
};


class Game{
  private: 
    vector<Die> dice; 
    int roll;
    vector<int> upperScores;
    vector<int> lowerScores;
    int round;
    int score;
    int total;
    ScoringFlags scoringFlags;
    void isThreeInARow(vector<int> diceValues);
    void isFourInARow(vector<int> diceValues);
    void isYahtzee(vector<int> diceValues);
    void isPair(vector<int> diceValues);
    void isSmallStraight(vector<int> diceValues);
    void isLargeStraight(vector<int> diceValues);
    void chance(vector<int> diceValues);
    void resetFlags();
    vector<int> pickedCategories;
  public:
    Game(); // Constructor to initialize the game with a certain number of dice
    vector<int> getDiceValues()const;
    vector<int> getRerollIndices()const;
    vector<int> getUpperScores()const;
    vector<int> getLowerScores()const;
    void setRoll(int index);
    int getRoll()const;
    void rollAllDice();
    void rerollDice(vector<int> indices);
    void updateScore(int category, int points);
    int getRound();
    void setRound(int r);
    int calculateScores(int category, vector<int> diceValues);
    void resetScore();
    void playGame();
    int getTotalScore();
    void setTotalScore();
    bool getPicked(int category);
    void markPicked(int category);
};





#endif