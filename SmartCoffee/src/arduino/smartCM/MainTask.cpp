#include "MainTask.h"
#include "Arduino.h"
#include "DistanceTask.h"
#include "MakeCoffeeTask.h"
#include "MovementTask.h"


const float DIST1 = 0.3;
const float DIST2 = 0.1;
const int DT1 = 1;
const int DT2a = 5;
const int DT2b = 5;
const int DT3 = 3;
const int DT4 = 5;

MainTask::MainTask(int pin)
{
  this->pinButton = pin;
}

void MainTask::init(int period)
{
  Task::init(period);
  button = new ButtonImpl(pinButton);
  state = STANBY;
  timeStandby = 0;
  timeReady = 0;
  timerOn = 0;
}

void MainTask::tick()
{
  switch (state)
  {
  case STANDBY:
    if (MovementTask::movement)
    {
      state = ON;
    }
    break;

  case ON1:
    if (DistanceTask::distance < DIST1)
    {
      timeOn = 0;
      state = ON2;
      /*if(!movement){
      tim
    } QUI DOVREMMO METTERE IL RITORNO A STANDBY MA NON SAPPIAMO COME AZZERARE timeStandby*/
      break;
    case ON2:
      if (distance > DIST1)
      {
        state = ON1;
      }
      else
      {
        timeOn += 50;
        if (timeOn >= (DT1 * 1000))
        {
          state = READY1;
        }
      }
      break;

    case READY1:
      if (distance > DIST1)
      {
        timeReady = 0;
        state = READY2;
      }
      if (button->isPressed())
      {
        state = MAKECOFFEE;
        makeCoffee = true;
      }
      break;

    case READY2:
      if (distance > DIST1)
      {
        timeReady += 50;
        if (timeReady >= DT2)
        {
          state = ON1;
        }
      }
      else
      {
        state = READY1;
      }
      break;

    case MAKECOFFEE:

      break;

    case MAINTAINCE:

      break;
    }
  }
