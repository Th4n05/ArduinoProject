#ifndef __MOVEMENTTASK__
#define __MOVEMENTTASK__

#include "Task.h"
#include "PirSensor.h"

extern bool movement;


class MovementTask: public Task {

    int pin;
    PirSensor* pir;

  public:

    MovementTask(int pin);
    void init(int period);
    void tick();
};

#endif
