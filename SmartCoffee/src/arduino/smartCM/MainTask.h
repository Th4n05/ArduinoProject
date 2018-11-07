#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"

class MainTask: public Task {

  external bool movement;
  external float distance;
  external bool makeCoffee;
  enum {STANDBY, ON, READY, MAKECOFFEE, MAINTAINCE} state;
  int timeOn;
  int timeReady;
  int timeStandby;


public:

  MainTask();  
  void init(int period);  
  void tick();
};

#endif
