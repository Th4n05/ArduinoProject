#include "LedFaded.h"
#include "Arduino.h"

LedFaded::LedFaded(int pin)
{
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

void LedFaded::switchOn()
{
  analogWrite(pin, 255);
};

void LedFaded::setIntensity(int intensity)
{
  analogWrite(pin, intensity);
}

void LedFaded::switchOff()
{
  analogWrite(pin, 0);
};
