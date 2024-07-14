#include "../header_files/Die.h"



Die::Die(): // constructor that initializes each die with desired sides
SIDES(6)
{
  roll();
}

void Die::roll(){
  faceValue = rand() % SIDES + 1;
}

int Die::getSides()const{
  return SIDES;
}


int Die::getFaceValue()const{
  return faceValue;
}
