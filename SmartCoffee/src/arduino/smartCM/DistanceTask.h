#ifndef __DISTANCETASK__
#define __DISTANCETASK__

#include "Task.h"
#include "SonarImpl.h"


class DistanceTask: public Task {

  int echoPin;
  int trigPin;
  SonarImpl* sonar;
  float distance;

public:

  DistanceTask(int echo, int trig);  
  void init(int period);  
  void tick();
};

#endif
