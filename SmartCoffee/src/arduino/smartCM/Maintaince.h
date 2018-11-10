#ifndef __MOVEMENTTASK__
#define __MOVEMENTTASK__

#include "Task.h"
#include "MainTask.h"
#include "MsgService.h"


class Maintaince: public Task {

  char pressButton;
  int numRecharge;

public:

  Maintaince();  
  void init(int period);
  void tick();
};

#endif
