#ifndef __AUTOMODETASK__
#define __AUTOMODETASK__

#include "Task.h"
#include "Led.h"


extern bool irrigation;

class AutoModeTask: public Task {

  int ledPin;
  Led* L1;

  public:

    AutoModeTask(int pin);
    void init(int period);
    void tick();
};

#endif
