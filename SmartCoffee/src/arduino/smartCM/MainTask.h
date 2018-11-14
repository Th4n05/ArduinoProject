#ifndef __MAINTASK__
#define __MAINTASK__

#include "Task.h"
#include "ButtonImpl.h"
#include "PotentiometerImpl.h"

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
    int precSugarLevel;
    ButtonImpl *button;
    PotentiometerImpl *regulator;
    int period;
    //dovremmo includere anche il potenziometro

  public:
    MainTask(int pin);
    void init(int period);
    void tick();
    void energySaving();
    void sugarRegulator();
    void checkMaintaince();
};

#endif
