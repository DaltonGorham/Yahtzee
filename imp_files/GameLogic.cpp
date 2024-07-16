#include "../header_files/GameLogic.h"
#include "../header_files/ConsoleUI.h"
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;


Game::Game() : dice(5), upperScores(6), lowerScores(7), pickedCategories(0) // Initialize the game 
{
  score = 0; 
  total = 0;
} 


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

void Game::resetScore(){
  score = 0;
}



void Game:: playGame(){
 srand(time(0));  // Seed for random faceValue
  
  Console ui;
  Game yahtzee;
  Die die;


  ui.clearScreen(); // Clear previous round

  ui.welcomeMessage();
  
  
  int count = 0;  // start of game
  while(count < 13){
  yahtzee.setRound(count + 1);
  ui.displayRound(yahtzee.getRound());


  // start first round
  yahtzee.setRoll(1);  
  ui.displayRoll(yahtzee.getRoll());

  yahtzee.rollAllDice();

  vector<int> diceValues = yahtzee.getDiceValues();

  ui.displayDice(diceValues);


  
  // Ask for reroll and display new value for dice
  for (int i = 0; i < 2; i++){   
    if (ui.askReroll()){
      yahtzee.setRoll(i + 2);
      vector<int> indices = yahtzee.getRerollIndices(); // get desired reroll die
      yahtzee.rerollDice(indices);  
      diceValues = yahtzee.getDiceValues(); // Get the new values of the die
      ui.clearScreen();
      ui.displayRoll(yahtzee.getRoll());
      ui.displayDice(diceValues);  // Display the new die values
    } 
    else break;  // Exit the loop if no reroll is desired
  }

    ui.clearScreen();
    ui.currentDieMessage();
    ui.displayDice(diceValues);
    if (count == 0){
      ui.displayScoreCard();
    } else {
      ui.displayUpdateScoreCard(yahtzee);
    }

    int category = ui.scoreSelect();
    score = yahtzee.calculateScores(category, diceValues);
    yahtzee.updateScore(category, score);
    yahtzee.setTotalScore();
    ui.clearScreen();
    ui.displayUpdateScoreCard(yahtzee);
    cin.ignore();
    ui.buffer();
    ui.clearScreen();
    cout << endl;
    count++;  // increment count for round
  }
  ui.clearScreen();
  ui.displayFinalScore(yahtzee);
 
  
}

void Game::isThreeInARow(vector<int> diceValues){
 for (int i = 0; i < diceValues.size() - 2; i++){
    if (diceValues[i] == diceValues[i + 1] &&  diceValues[i + 1] == diceValues[i + 2]){
      scoringFlags.threeInARow = true;
    }
    
  }
}

void Game::isFourInARow(vector<int> diceValues){
  for (int i = 0; i < diceValues.size() - 1; i++){
    if (diceValues[i] == diceValues[i + 1] && diceValues[i+1] ==
     diceValues[i + 2] && diceValues[i + 2] == diceValues[i + 3]){
    scoringFlags.fourInARow = true;
  } 
  
}
}

void Game::isPair(vector<int> diceValues){
  for (int i = 0; i < diceValues.size(); i++){
    if (diceValues[i] == diceValues[i+1]){
      scoringFlags.pair = true;
    }
  }
}

void Game::isSmallStraight(vector<int> diceValues){
for (int i = 0; i <= diceValues.size() - 4; i++) {
    if (diceValues[i + 1] == diceValues[i] + 1 &&
        diceValues[i + 2] == diceValues[i] + 2 &&
        diceValues[i + 3] == diceValues[i] + 3) {
        scoringFlags.smallStraight = true;
      }
    }
}


void Game::isLargeStraight(vector<int> diceValues){
 for (int i = 0; i <= diceValues.size() - 5; i++) {
    if (diceValues[i + 1] == diceValues[i] + 1 &&
        diceValues[i + 2] == diceValues[i] + 2 &&
        diceValues[i + 3] == diceValues[i] + 3 &&
        diceValues[i + 4] == diceValues[i] + 4) {
        scoringFlags.largeStraight = true;
      }
  }
}

void Game::isYahtzee(vector<int> diceValues){
  for (int i = 0; i < diceValues.size(); i++){
  if (diceValues[i] == diceValues[i + 1] && diceValues[i + 1] == diceValues[i + 2]
  && diceValues[i + 2] == diceValues[i + 3] && diceValues[i + 3] == diceValues[i + 4]){
    scoringFlags.Yahtzee = true;
  } 
}
}

void Game::chance(vector<int> diceValues){
  for (int i = 0; i < diceValues.size(); i++){
    score += diceValues[i];
  }
}


int Game::calculateScores(int category, vector<int> diceValues){
  Console ui;


  resetScore(); // score back to 0
  resetFlags();
  
  for (int i = 0; i < ui.getUpperSection().size(); i++) {
    if (diceValues[i] == category) {
        score += diceValues[i];
    }
}

  sort(diceValues.begin(), diceValues.end());


  isThreeInARow(diceValues);

 if (category == 7 && scoringFlags.threeInARow) {
    for (int i = 0; i < diceValues.size(); i++) {
        score += diceValues[i];
    }
}

  isFourInARow(diceValues);


   if (category == 8 && scoringFlags.fourInARow) {
    for (int i = 0; i < diceValues.size(); i++) {
        score += diceValues[i];
    }
}


  if (category == 9){
    isPair(diceValues);
    isThreeInARow(diceValues);
  }
 

  if(category == 9 && scoringFlags.threeInARow && scoringFlags.pair){
    score = 25;
  }


  isSmallStraight(diceValues);

  if (category == 10 && scoringFlags.smallStraight){
    score = 30;
  }


  isLargeStraight(diceValues);

  if (category == 11 && scoringFlags.largeStraight){
    score = 40;
  }


  isYahtzee(diceValues);

  if (category == 12 && scoringFlags.Yahtzee){
    score = 50;

  }


  if (category == 13){
  chance(diceValues);
  
}

  

  return score;

}


bool Game::getPicked(int category){

  for (int picked : pickedCategories){
    if (category == picked){
      return true;
    }
  }
  return false;
}


void Game::setTotalScore(){
  total = 0;
  for (int Score : upperScores){
    total += Score;
  }
  
  for (int Score : lowerScores){
    total += Score;
  }

}

int Game::getTotalScore(){
  return total;
}


void Game::resetFlags(){
  scoringFlags.pair = false;
  scoringFlags.threeInARow = false;
  scoringFlags.fourInARow = false;
  scoringFlags.Yahtzee = false;
  scoringFlags.smallStraight = false;
  scoringFlags.largeStraight = false;
}

void Game::markPicked(int category){
  pickedCategories.push_back(category);
}