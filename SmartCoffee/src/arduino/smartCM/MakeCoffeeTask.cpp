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
  for (int i = 0; i < 3; i++)
  {
    led[i] = new Led(pin[i]);
  }
  num = -1;
}

void MakeCoffeeTask::tick()
{
  if (makeCoffee)
  {
    if (num == -1)
    {
      num = (num + 1);
      led[num]->switchOn();
      delayMicroseconds(10000);
    }
    else
    {
      led[num]->switchOff();
      num = (num + 1);
      led[num]->switchOn();
      delayMicroseconds(10000);
    }
    if (num >= 2)
    {
      makeCoffee = false;
      num = -1;
    }
  }
}
