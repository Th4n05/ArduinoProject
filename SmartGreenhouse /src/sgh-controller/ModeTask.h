#ifndef __MODETASK__
#define __MODETASK__

#include "Task.h"


extern bool manualMode;


class MainTask : public Task
{
    int period;

  public:
    MainTask();
    void init(int period);
    void tick();
};

#endif
