#include "MakeCoffeeTask.h"
#include "Arduino.h"

MakeCoffeeTask::MakeCoffeeTask(int pin0, int pin1, int pin2)
{
  this->pin[0] = pin0;
  this->pin[1] = pin1;
  this->pin[2] = pin2;
}

void MakeCoffeeTask::init(int period)
{
  Task::init(period);
  this->period = period;
  for (int i = 0; i < 3; i++)
  {
    led[i] = new Led(pin[i]);
  }
  num = -1;
  timeLed = 0;
}

void MakeCoffeeTask::tick()
{
  if (makeCoffee)
  {
    if (timeLed >= 1000) {

      if (num == -1)
      {
        num = (num + 1);
        led[num]->switchOn();
        timeLed = 0;
      }
      else
      {
        led[num]->switchOff();
        num = (num + 1);
        led[num]->switchOn();
        timeLed = 0;
      }
      if (num >= 2)
      {
        timeLed = 0;
        makeCoffee = false;
        num = -1;
      }
    }
    else {
      timeLed += period;
    }
  }
}
