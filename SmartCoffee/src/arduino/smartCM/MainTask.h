#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"

class MainTask : public Task
{

    external bool movement;
    external float distance;
    external bool makeCoffee;
    enum
    {
        STANDBY,
        ON1,
        ON2,
        READY1,
        READY2,
        MAKECOFFEE,
        MAINTAINCE
    } state;
    int timeOn;
    int timeReady;
    int timeStandby;
    int pinButton;
    Button *button;
    //dovremmo includere anche il potenziometro

  public:
    MainTask(int pin);
    void init(int period);
    void tick();
};

#endif
