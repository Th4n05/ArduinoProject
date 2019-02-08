#ifndef __DISTANCETASK__
#define __DISTANCETASK__

#include "Task.h"
#include "SonarImpl.h"
#include "SharedState.h"


class DistanceTask: public Task {

    SharedState* pSharedState;
    int echoPin;
    int trigPin;
    SonarImpl* sonar;

  public:

    DistanceTask(SharedState* pState, int echo, int trig);
    void init(int period);
    void tick();
};

#endif
