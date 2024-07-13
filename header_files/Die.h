#ifndef Die_H
#define Die_H
#include <iostream>
using namespace std;

class Die{
  private:
    const int SIDES;
    int faceValue;
  public:
    Die();
    void roll();
    int getFaceValue()const;
    int getSides()const;
};





#endif