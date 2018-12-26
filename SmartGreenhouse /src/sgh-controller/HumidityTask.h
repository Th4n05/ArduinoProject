#ifndef __HUMIDITYTASK__
#define __HUMIDITYTASK__

#include "Task.h"
#include "HumiditySensorImpl.h"

extern float humidity;


class HumidityTask: public Task {

    int pin;
    HumiditySensorImpl* humSensor;

  public:

    HumidityTask(int pin);
    void init(int period);
    void tick();
};

#endif
