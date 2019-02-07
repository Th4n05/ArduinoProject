#ifndef __HUMIDITYTASK__
#define __HUMIDITYTASK__

#include "Task.h"
#include "SharedState.h"


class HumidityTask : public Task
{
    SharedState *pSharedState;

  public:
    HumidityTask(SharedState* pState);
    void init(int period);
    void tick();
};

#endif
