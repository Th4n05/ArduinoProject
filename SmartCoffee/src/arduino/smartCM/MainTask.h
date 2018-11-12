#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"
#include "ButtonImpl.h"

extern int state;
extern int numCoffee;
extern bool maintaince;


class MainTask : public Task
{
    int timeOn;
    int timeReady;
    int timeStandby;
    int timeCoffee;
    int pinButton;
    int pinPotentiometer;
    int sugarLevel;
    ButtonImpl *button;
    PotentiometerImpl *regulator;
    int period;
    //dovremmo includere anche il potenziometro

  public:
    MainTask(int pin , uint8_t analog);
    void init(int period);
    void tick();
    void energySaving();
    void sugarRegulator();
    void checkMaintaince();
};

#endif
