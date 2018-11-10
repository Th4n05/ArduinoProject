#ifndef __MAKECOFFEETASK__
#define __MAKECOFFEETASK__

#include "Task.h"
#include "Led.h"
extern bool makeCoffee;


class MakeCoffeeTask : public Task
{

    int pin[3];
    Light *led[3];
    int num;

  public:
    MakeCoffeeTask(int pin0, int pin1, int pin2);
    void init(int period);
    void tick();
};

#endif
