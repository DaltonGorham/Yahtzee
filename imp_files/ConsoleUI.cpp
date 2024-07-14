#include "../header_files/ConsoleUI.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;


void Console::welcomeMessage() {
  cout << "Welcome to Yahtzee!" << endl;
  cout << "Press Enter to Continue" << endl;
  cin.get();   // Wait for the user to press Enter
}


void Console::displayDice(vector<int> diceValues)const{
  
  for (int i = 0; i < diceValues.size(); i++){
    cout << "Die " << i + 1 << " : " << diceValues[i] << endl;
  }
  cout << endl;
}

bool Console::askReroll(){
  char choice;
  cout << "Do you wish to reroll any die? (Y/N)" << endl;
  cin >> choice;
  cin.ignore();
  return choice == 'y' || choice == 'Y'; // Returns true if the user wants to reroll
  
}



vector<int> Console::getRerollIndices()const{
  vector<int> indices;
  int input;
  
  while (true) {
    cout << "Enter the die you wish to reroll (1-5), or 0 to finish" << endl;
    cin >> input;
    if (input == 0) break;   // Exit the loop if 0 is entered
    if (input >= 1 && input <= 5){
      indices.push_back(input - 1); // Back to 0-based-index
    } else {
      cout << "Invalid Die Number. PLease enter a number 1-5, or 0 to finish. " << endl;
    }
  }
  return indices; // Return the list of indices to reroll
}

void Console::displayRound(int index){
  cout << "Round " << index << endl;
}


void Console::clearScreen(){
  cout << "\033[2J\033[1;1H";
}
