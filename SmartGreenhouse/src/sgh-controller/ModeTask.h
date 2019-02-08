#ifndef __MODETASK__
#define __MODETASK__

#include "Task.h"
#include "SharedState.h"
#include "Led.h"

class ModeTask : public Task
{
  SharedState* pSharedState;
  Led* LM;
  Led* L1;
  int period;

public:
  ModeTask(SharedState* pState);
  void init(int period);
  void tick();
};

#endif
