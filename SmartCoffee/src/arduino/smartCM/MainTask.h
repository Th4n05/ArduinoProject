#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"
#include "ButtonImpl.h"

extern int state;


class MainTask : public Task
{
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
