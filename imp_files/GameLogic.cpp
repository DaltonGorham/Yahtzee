#include "../header_files/GameLogic.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;


Game::Game() : dice(5){}  // Initialize the game with 5 dice


void Game::rollAllDice(){ // Roll each die
  for (Die die : dice){  
    die.roll();
  }
}

void Game::rerollDice(vector<int> indices){
  for (int index : indices){
    if (index >= 0 && index < dice.size()){ // Check if the index is valid
      dice[index].roll(); // Reroll the specified die 
    }
  }
}

vector<int> Game::getDiceValues()const{
  vector<int> values;
  for (Die die : dice){
    values.push_back(die.getFaceValue());  // Get the face value of each die
  }
  return values;  // Return the list of dice values
}


void Game::setRound(int index){
  round = index;
}

int Game::getRound()const{
  return round;
}

