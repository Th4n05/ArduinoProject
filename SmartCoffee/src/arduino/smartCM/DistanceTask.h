#ifndef __DISTANCETASK__
#define __DISTANCETASK__

#include "Task.h"
#include "Sonar.h"

class DistanceTask: public Task {

  int echoPin;
  int trigPin;
  Sonar* sonar;
  external float distance;
  external enum state;

public:

  DistanceTask(int echo, int trig);  
  void init(int period);  
  void tick();
};

#endif
