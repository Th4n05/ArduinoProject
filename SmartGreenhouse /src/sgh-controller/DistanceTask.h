#ifndef __DISTANCETASK__
#define __DISTANCETASK__

#include "Task.h"
#include "SonarImpl.h"

extern float distance;


class DistanceTask: public Task {

    int echoPin;
    int trigPin;
    SonarImpl* sonar;

  public:

    DistanceTask(int echo, int trig);
    void init(int period);
    void tick();
};

#endif
