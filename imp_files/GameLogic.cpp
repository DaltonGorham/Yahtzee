#include "../header_files/GameLogic.h"
#include "../header_files/ConsoleUI.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;


Game::Game() : dice(5), upperScores(6), lowerScores(7){}  // Initialize the game 


void Game::rollAllDice(){ // Roll each die
  for (int i = 0; i < dice.size(); i++){
    dice[i].roll();
  }
}


vector<int> Game::getRerollIndices()const{
  vector<int> indices;
  int input;
  Console ui;
  
  while (true) {
    ui.displayDieSelection();
    cin >> input;
    if (input == 0) break;   // Exit the loop if 0 is entered
    if (input >= 1 && input <= 5){
      indices.push_back(input - 1); // Back to 0-based-index
    } else {
      ui.displayInvalidDie();
    }
    if (indices.size() == 5){ // Exit if all 5 die have been rerolled
      break;
    }
  }
  return indices; // Return the list of indices to reroll
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


void Game::setRoll(int index){
  roll = index;
}

int Game::getRoll()const{
  return roll;
}

int Game::getRound(){
  return round;
}

void Game::setRound(int r){
  round = r;
}


vector<int> Game::getUpperScores()const{
  return upperScores;
}

vector<int> Game::getLowerScores()const{
  return lowerScores;
}

void Game::updateScore(int category, int points){
  if (category >= 1 && category <= 6){
    upperScores[category - 1] = points;
  } else if (category >= 7 && category <= 13){
    lowerScores[category - 7] = points;
  } else {
    cout << "Invalid Category";
  }
}