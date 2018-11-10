#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"
#include "ButtonImpl.h"

class MainTask : public Task
{
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
    ButtonImpl *button;
    //dovremmo includere anche il potenziometro

  public:
    MainTask(int pin);
    void init(int period);
    void tick();
};

#endif
