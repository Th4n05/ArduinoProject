#ifndef __SONARIMPL__
#define __SONARIMPL__

#include "Sonar.h"

class SonarImpl : public Sonar
{

  public:
    SonarImpl(int pin);
    float getDistance();

  private:
    int pin;
};

#endif
