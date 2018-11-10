#ifndef __MOVEMENTTASK__
#define __MOVEMENTTASK__

#include "Task.h"
#include "PirSensorImpl.h"


class MovementTask: public Task {

  int pin;
  PirSensorImpl* pir;
  bool movement;

public:

  MovementTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
