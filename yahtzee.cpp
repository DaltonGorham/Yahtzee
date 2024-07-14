#include "./imp_files/Die.cpp"
#include "./imp_files/GameLogic.cpp"
#include "./imp_files/ConsoleUI.cpp"
#include <iostream>
#include <ctime>
using namespace std;




int main(){
  // Seed for random faceValue
  srand(time(0));
  
  Console ui;
  Game yahtzee;
  Die die;


  ui.welcomeMessage();

   //start first round
  yahtzee.setRound(1);
  ui.displayRound(yahtzee.getRound());

  yahtzee.rollAllDice();

  vector<int> diceValues = yahtzee.getDiceValues();

  ui.displayDice(diceValues);

  
  // Ask for reroll and display new value for dice
  for (int i = 0; i < 2; i++){   
    if (ui.askReroll()){
      yahtzee.setRound(i + 2);
      vector<int> indices = ui.getRerollIndices(); // get desired reroll die
      yahtzee.rerollDice(indices);  
      diceValues = yahtzee.getDiceValues(); // Get the new values of the die
      ui.clearScreen();
      ui.displayRound(yahtzee.getRound());
      ui.displayDice(diceValues);  // Display the new die values
    } 
    else break;  // Exit the loop if no reroll is desired
  }








  return 0;
}