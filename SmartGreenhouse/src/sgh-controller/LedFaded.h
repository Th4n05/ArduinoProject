#ifndef __LEDFADED__
#define __LEDFADED__

#include "Light.h"

class Led: public Light { 
public:
  Led(int pin);
  void switchOn();
  void setIntensity(int intensity);
  void switchOff();    
private:
  int pin;  
};

#endif
