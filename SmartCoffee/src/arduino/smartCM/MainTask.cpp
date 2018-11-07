#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"


class MainTask: public Task {

  int pin[3];
  Light* led[3];
  int state;

public:

  ThreeLedsTask(int pin0, int pin1, int pin2);  
  void init(int period);  
  void tick();
};

#endif
