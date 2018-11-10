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
const int NMAX = 10;

MainTask::MainTask(int pin)
{
  this->pinButton = pin;
}

void MainTask::init(int period)
{
  Task::init(period);
  this->period = period;
  button = new ButtonImpl(pinButton);
  state = 0;
  timeStandby = 0;
  timeReady = 0;
  timeOn = 0;
}

void MainTask::tick()
{
  switch (state)
  {
    case 0:
      Serial.println("stato Stand By");
      if (movement)
      {
        state = 1;
      }
      break;

    case 1:

      Serial.println("stato On1");
      if (distance < DIST1)
      {

        timeOn = 0;
        state = 2;
        /*if(!movement){
          tim
          } QUI DOVREMMO METTERE IL RITORNO A STANDBY MA NON SAPPIAMO COME AZZERARE timeStandby*/
        break;
      case 2:
        Serial.println("stato ON2");

        if (distance > DIST1)
        {
          state = 1;
        }
        else
        {
          timeOn += period;
          if (timeOn >= (DT1 * 1000))
          {
            state = 3;
          }
        }
        break;

      case 3:
        Serial.println("stato READY1");

        if (distance > DIST1)
        {
          timeReady = 0;
          state = 4;
        }
        if (button->isPressed())
        {
          state = 5;
          makeCoffee = true;
          numCoffee--;
        }
        break;

      case 4:
        Serial.println("stato READY2");

        if (distance > DIST1)
        {
          timeReady += period;
          if (timeReady >= (DT2a * 1000)) // ho messo a ma non so quale dei 2 DT2 sia
          {
            state = 1;
          }
        }
        else
        {
          state = 3;
        }
        break;

      case 5:
        Serial.println("stato MAKECOFFEE");
        if(!makeCoffee){ //vuol dire che il caffè è stato fatto.
        state = 3;
        
        /*if ((numCoffee - NMAX) == 0) {
          state = 6;
        }else{
          
        }*/}

        break;

      case 6:
        Serial.println("stato MAINTAINCE");


        break;
      }
  }
}
