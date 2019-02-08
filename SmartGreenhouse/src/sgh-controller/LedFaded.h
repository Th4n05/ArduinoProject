#ifndef __LEDFADED__
#define __LEDFADED__

#include "Light.h"

class LedFaded: public Light { 
public:
  LedFaded(int pin);
  void switchOn();
  void setIntensity(int intensity);
  void switchOff();    
private:
  int pin;  
};

#endif
