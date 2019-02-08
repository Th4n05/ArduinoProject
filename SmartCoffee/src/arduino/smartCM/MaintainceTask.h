#ifndef __MAINTAINCETASK__
#define __MAINTAINCETASK__

#include "Task.h"

extern bool maintaince;
extern int numCoffee;


class MaintainceTask : public Task
{

  int NC;

public:
  MaintainceTask();
  void init(int period);
  void tick();
};

#endif
