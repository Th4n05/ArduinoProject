#include "SugarRegulatorImpl.h"
#include "Arduino.h"

SugarRegulatorImpl::SugarRegulatorImpl(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool SugarRegulatorImpl::getSugar()
{
    int value = analogRead(pin);
    if (value >= 0 && value < 205)
    {
        return 1;
    }
    if (value >= 205 && value < 410)
    {
        return 2;
    }
    if (value >= 410 && value < 615)
    {
        return 3;
    }
    if (value >= 615 && value < 820)
    {
        return 4;
    }
    if (value >= 820 && value < 1024)
    {
        return 5;
    }
    return 0;
}
