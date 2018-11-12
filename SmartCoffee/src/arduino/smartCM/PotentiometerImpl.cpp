#include "PotentiometerImpl.h"
#include "Arduino.h"

PotentiometerImpl::PotentiometerImpl(uint8_t pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

int PotentiometerImpl::isMoved()
{
    float value = analogRead(pin);
    if (value >= 0 && value < 204)
    {
        return 0;
    }
    else if (value >= 204 && value < 408)
    {
        return 1;
    }
    else if (value >= 408 && value < 612)
    {
        return 2;
    }
    else if (value >= 612 && value < 816)
    {
        return 3;
    }
    else if (value >= 816 && value <= 1023)
    {
        return 4;
    }
    else
    {
        return 2; //situazione di default
    }
}
