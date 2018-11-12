#ifndef __POTENTIOMETERIMPL__
#define __POTENTIOMETERIMPL__

#include "Potentiometer.h"

class PotentiometerImpl : public Potentiometer {
 
public: 
  PotentiometerImpl(uint8_t pin);
  int getValue();

private:
  uint8_t pin;
};

#endif
