#include "../header_files/ConsoleUI.h"
#include "../header_files/Die.h"
#include "../header_files/GameLogic.h"
#include <iostream>
using namespace std;



void Console::displayDice(vector<int> diceValues)const{
  for (int value : diceValues){
    cout << value << " ";
  }
  cout << endl;
}