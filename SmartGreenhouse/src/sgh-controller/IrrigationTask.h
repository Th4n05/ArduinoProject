#ifndef __IRRIGATIONTASK__
#define __IRRIGATIONTASK__

#include "Task.h"
#include "servo_motor_impl.h"
#include "SharedState.h"

class IrrigationTask : public Task
{

    SharedState *pSharedState;
    ServoMotor *pMotor;
    int pos;
    int delta;
    int precPos;

  public:
    IrrigationTask(SharedState *pState);
    void init(int period);
    void tick();
};

#endif
