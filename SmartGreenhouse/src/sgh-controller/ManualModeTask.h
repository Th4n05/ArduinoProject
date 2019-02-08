#ifndef __MANUALMODETASK__
#define __MANUALMODETASK__

#include "Task.h"
#include "Led.h"
#include "SharedState.h"



class ManualModeTask: public Task {

    SharedState* pSharedState;

  public:

    ManualModeTask(SharedState* pState);
    void init(int period);
    void tick();
};

#endif
