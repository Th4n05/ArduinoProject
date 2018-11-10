#ifndef __MOVEMENTTASK__
#define __MOVEMENTTASK__

#include "Task.h"

class Maintaince: public Task {

  char pressButton;
  int numRecharge;

public:

  Maintaince();
  void init(int period);
  void tick();
};

#endif
