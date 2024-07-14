#include "./imp_files/Die.cpp"
#include "./imp_files/GameLogic.cpp"
#include "./imp_files/ConsoleUI.cpp"
#include <iostream>
#include <ctime>
using namespace std;




int main(){

  srand(time(0));   // Seed for random faceValue
  
  Console ui;
  Game yahtzee;
  Die die;


  ui.clearScreen(); // Clear previous round

  ui.welcomeMessage();


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
    ui.displayScoreCard();









  return 0;
}