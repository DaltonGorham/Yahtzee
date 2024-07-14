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


vector<int> Game::getRerollIndices()const{
  vector<int> indices;
  int input;
  
  while (true) {
    cout << "Enter the die you wish to reroll (1-5), or 0 to finish" << endl;
    cin >> input;
    if (input == 0) break;   // Exit the loop if 0 is entered
    if (input >= 1 && input <= 5){
      indices.push_back(input - 1); // Back to 0-based-index
    } else {
      cout << "Invalid Die Number." << endl;
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

