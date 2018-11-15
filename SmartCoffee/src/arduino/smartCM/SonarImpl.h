#ifndef __SONARIMPL__
#define __SONARIMPL__

#include "Sonar.h"

class SonarImpl : public Sonar
{

  public:
    SonarImpl(int trig, int echo);
    float getDistance();

  private:
    int trigPin;
    float averageDistance;
    float alpha;
    int echoPin;
};

#endif
