#include "../header_files/ConsoleUI.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;


void Console::welcomeMessage() {
  cout << "Welcome to Yahtzee!" << endl;
  cout << "Press Enter to Continue" << endl;
  cin.get();
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
  return choice == 'y' || choice == 'Y';
  
}



vector<int> Console::getRerollIndices()const{
  vector<int> indices;
  int input;
  
  while (true) {
    cout << "Enter the die you wish to reroll (1-5), or 0 to finish" << endl;
    cin >> input;
    if (input == 0) break;
    if (input >= 1 && input <= 5){
      indices.push_back(input - 1); //Back to 0-based-index
    } else {
      cout << "Invalid Die Number. PLease enter a number 1-5, or 0 to finish. " << endl;
    }
  }
  return indices;
  



}

