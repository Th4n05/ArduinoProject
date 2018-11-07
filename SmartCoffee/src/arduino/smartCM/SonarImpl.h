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
    int echoPin;
};

#endif
