#ifndef __MOVEMENTTASK__
#define __MOVEMENTTASK__

#include "Task.h"
#include "PirSensorImpl.h"

extern bool movement;


class MovementTask: public Task {

    int pin;
    PirSensorImpl* pir;

  public:

    MovementTask(int pin);
    void init(int period);
    void tick();
};

#endif
