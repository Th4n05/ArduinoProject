#ifndef __AUTOMODETASK__
#define __AUTOMODETASK__

#include "Task.h"
#include "Led.h"
#include "SharedState.h"



class AutoModeTask: public Task {

    SharedState* pSharedState;
    Led* L2;
    enum { IDLE, CHOOSE, WAIT, ERROR } state;
    int erogationTime;
    int period;

  public:

    AutoModeTask(SharedState* pState);
    void init(int period);
    void tick();
};

#endif
