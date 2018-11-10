#ifndef __MOVEMENTTASK__
#define __MOVEMENTTASK__

#include "Task.h"
#include "PirSensor.h"

class MovementTask: public Task {

  int pin;
  PirSensor* pir;
  bool movement;

public:

  MovementTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
