#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"
#include "ButtonImpl.h"

extern int state;
extern int numCoffee;


class MainTask : public Task
{
    int timeOn;
    int timeReady;
    int timeStandby;
    int timeCoffee;
    int pinButton;
    ButtonImpl *button;
    int period;
    //dovremmo includere anche il potenziometro

  public:
    MainTask(int pin);
    void init(int period);
    void tick();
};

#endif
