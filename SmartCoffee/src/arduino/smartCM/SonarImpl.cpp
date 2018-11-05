#include "SonarImpl.h"
#include "Arduino.h"

SonarImpl::SonarImpl(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

float SonarImpl::getDistance()
{
    return analogRead(pin);
}
