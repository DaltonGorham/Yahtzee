#include "../header_files/GameLogic.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;


Game::Game() : dice(5){}




void Game::rollAllDice(){
  for (Die die : dice){
    die.roll();
  }
}

void Game::rerollDice(vector<int> indices){
  for (int index : indices){
    if (index >= 0 && index < dice.size()){
      dice[index].roll();
    }
  }
}

vector<int> Game::getDiceValues()const{
  vector<int> values;
  for (Die die : dice){
    values.push_back(die.getFaceValue());
  }
  return values;
}
