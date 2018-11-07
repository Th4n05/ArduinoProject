#ifndef __MAKECOFFEETASK__
#define __MAKECOFFEETASK__

#include "Task.h"
#include "Led.h"

class MakeCoffeeTask: public Task {

  int pin[3];
  Light* led[3];
  int state;

public:

  MakeCoffeeTask(int pin0, int pin1, int pin2);  
  void init(int period);  
  void tick();
};

#endif
