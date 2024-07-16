#include "./imp_files/Die.cpp"
#include "./imp_files/GameLogic.cpp"
#include "./imp_files/ConsoleUI.cpp"
#include <iostream>
#include <ctime>
using namespace std;




int main(){

  Game yahtzee;
  char answer;
  do {
  yahtzee.playGame();
  
  cout << "Do you want to play again?" << endl;
  cin >> answer;
  cin.ignore();
  } while (answer == 'y' || answer == 'Y');

 

  return 0;
}