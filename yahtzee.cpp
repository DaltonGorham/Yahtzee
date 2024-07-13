#include "./imp_files/Die.cpp"
#include "./imp_files/GameLogic.cpp"
#include "./imp_files/ConsoleUI.cpp"
#include <iostream>
#include <ctime>
using namespace std;




int main(){

  srand(time(0));

  Console ui;
  Game yahtzee;
  Die die;


  ui.welcomeMessage();




  //start first round
  yahtzee.rollAllDice();

  vector<int> diceValues = yahtzee.getDiceValues();

  ui.displayDice(diceValues);

  

  //asks for reroll and display new value for dice.

          //two more rerolls left
  for (int i = 0; i < 2; i++){
    if (ui.askReroll()){
      vector<int> indices = ui.getRerollIndices();
      yahtzee.rerollDice(indices);
      diceValues = yahtzee.getDiceValues();
      ui.displayDice(diceValues);
    } 
    else break;
  }










  return 0;
}