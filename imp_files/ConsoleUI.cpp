#include "../header_files/ConsoleUI.h"
#include "../header_files/GameLogic.h"
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;


void Console::welcomeMessage() {
  cout << "Welcome to Yahtzee!" << endl;
  cout << "Press Enter to Continue" << endl;
  cin.get();   // Wait for the user to press Enter
}


Console::Console(){ // Constructor: Initializes Score Card
   upperSection = {
      "1.)  Aces",
      "2.)  Twos",
      "3.)  Threes",
      "4.)  Fours",
      "5.)  Fives",
      "6.)  Sixes"
    };

   lowerSection = {
    "7.)  Three of a kind",
    "8.)  Four of a kind",
    "9.)  Full House",
    "10.) Small Straight",
    "11.) Large Straight",
    "12.) Yahtzee",
    "13.) Chance"
  };
}


void Console::displayDice(vector<int> diceValues)const{
  
  for (int i = 0; i < diceValues.size(); i++){
    cout << "Die " << i + 1 << " : " << diceValues[i] << endl;
  }
  cout << endl;
}


bool Console::askReroll(){
  char choice;
  do {
  cout << "Do you wish to reroll any die? (Y/N)" << endl;
  cin >> choice;
  cin.ignore();
  cin.clear();
  } while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
  return choice == 'y' || choice == 'Y'; // Returns true if the user wants to reroll
  
}


void Console::displayRoll(int index){
  cout << "Roll " << index << endl;
}


void Console::displayDieSelection(){
  cout << "Enter the die you wish to reroll (1-5), or 0 to finish" << endl;
}


void Console::displayInvalidDie(){
  cout << "Invalid Die Number." << endl;
}


void Console::clearScreen(){
  cout << "\033[2J\033[1;1H";
}


void Console::currentDieMessage(){
  cout << "What you have: " << endl;
}


void Console::displayScoreCard(){
  cout << "SCORE CARD" << endl << endl;

  cout << "UPPER SECTION:" << endl;

  for (string selection : upperSection){
    cout << selection << endl;
  }

  cout << endl << "LOWER SECTION:" << endl;

  for (string selection : lowerSection){
    cout << selection << endl;
  }

}

void Console::buffer(){
  cout << endl << endl << "Press Enter to Continue";
  cin.get();
}

void Console::displayRound(int round){
  cout << "Round " << round << ": ";
}

int Console::scoreSelect(){
  int number;
   do {
      cout << "Select a number to score in: ";
      cin >> number;

      if (number < 1 || number > 13) {
          cout << "Invalid input. Please enter a number between 1 and 13." << endl;
      } else if (game.getPicked(number)) {
          cout << "That category is already taken. Please choose another." << endl;
      }

  } while (number < 1 || number > 13 || game.getPicked(number));

  game.markPicked(number);

    return number;

}


 vector<string> Console::getUpperSection(){
  return upperSection;
 };


 
 vector<string> Console::getLowerSection(){
  return lowerSection;
 };

void Console::displayUpdateScoreCard(Game game){
  cout << "SCORE CARD" << endl << endl;

  cout << "UPPER SECTION:" << endl;

  const vector<int> upperScores = game.getUpperScores();

  for (int i = 0; i < upperSection.size(); i++) {
      cout << upperSection[i] << " : " << upperScores[i] << endl;
  }

   cout << endl << "LOWER SECTION:" << endl;

   const vector<int> lowerScores = game.getLowerScores();

   for (int i = 0; i < lowerSection.size(); i++) {
      cout << lowerSection[i] << " : " << lowerScores[i] << endl;
   }


}


void Console::displayFinalScore(Game game){

  cout << endl << endl << "TOTAL SCORE: " << game.getTotalScore() << endl;
}

