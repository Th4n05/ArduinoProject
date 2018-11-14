#include "MainTask.h"
#include "Arduino.h"
#include "DistanceTask.h"
#include "MakeCoffeeTask.h"
#include "MovementTask.h"
#include "MsgService.h"
#include <avr/sleep.h>
#include <avr/power.h>

const float DIST1 = 0.3;
const float DIST2 = 0.1;
const int DT1 = 1;
const int DT2a = 5;
const int DT2b = 5;
const int DT3 = 3;
const int DT4 = 5;
const int NMAX = 3;

MainTask::MainTask(int pin)
{
  this->pinButton = pin;
}

void MainTask::init(int period)
{
  Task::init(period);
  this->period = period;
  button = new ButtonImpl(pinButton);
  regulator = new PotentiometerImpl();
  state = 0;
  maintaince = false;
  timeStandby = 0;
  sugarLevel = 2;
  precSugarLevel = 2;
  timeReady = 0;
  timeOn = 0;
  numCoffee = 0;
}

/*void sugarRegulator()
  {
  int value = regulator->getValue();
  if (value != sugarLevel)
  {
    sugarLevel = value;
    MsgService.sendMsg(sugarLevel);
  }
  }

  void energySaving()
  {
  Serial.println("Dormo");
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_enable();

  power_adc_disable();
  power_spi_disable();
  power_timer0_disable();
  power_timer2_disable();
  power_twi_disable();
  sleep_mode();
  sleep_disable();
  power_all_enable();
  Serial.println("Mi sveglio");
  }*/

void MainTask::tick()
{
  switch (state)
  {
    case 0:
      //Serial.println("stato Stand By");

      if (movement)
      {
        state = 1;
      }
      else
      {
        set_sleep_mode(SLEEP_MODE_IDLE);
        sleep_enable();

        /* Disable all of the unused peripherals. This will reduce power
                 consumption further and, more importantly, some of these
                 peripherals may generate interrupts that will wake our Arduino from
                 sleep!
        */
        power_adc_disable();
        power_spi_disable();
        power_timer0_disable();
        power_timer2_disable();
        power_twi_disable();
        /* Now enter sleep mode. */
        sleep_mode();
        /* The program will continue from here after the timer timeout*/
        sleep_disable(); /* First thing to do is disable sleep. */
        /* Re-enable the peripherals. */
        power_all_enable();
      }
      break;

    case 1:
      //Serial.println("stato On1");
      if (distance < DIST1)
      {
        timeOn = 0;
        state = 2;
      }
      else
      {
        if (!movement)
        {
          timeStandby += period;
          if (timeStandby >= (DT2b * 1000))
          {
            state = 0;
            MsgService.sendMsg("A");
          }
        }
        else
        {
          timeStandby = 0;
        }
      }

      break;
    case 2:
      //Serial.println("stato ON2");

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
          MsgService.sendMsg("W");
        }
      }
      break;

    case 3:
      //Serial.println("stato READY1");
      sugarLevel = regulator->getValue();
      if (precSugarLevel != sugarLevel)
      {
        precSugarLevel = sugarLevel;
        MsgService.sendMsg(String(sugarLevel));
      }
      if (distance > DIST1)
      {
        timeReady = 0;
        state = 4;
      }
      if (button->isPresse())
      {
        state = 5;
        MsgService.sendMsg("M");
        
        makeCoffee = true;
        timeCoffee = 0;
      }
      break;

    case 4:
      //Serial.println("stato READY2");
      if (distance > DIST1)
      {
        timeReady += period;
        if (timeReady >= (DT2a * 1000)) // ho messo a ma non so quale dei 2 DT2 sia
        {
          state = 1;
          timeStandby = 0;
        }
      }
      else
      {
        state = 3;
      }
      break;

    case 5:
      //Serial.println("stato MAKECOFFEE");
      if (!makeCoffee)
      { //vuol dire che il caffè è stato fatto.
        MsgService.sendMsg("R"); // da guardare come mandare una volta sola con un flag
        timeCoffee += period;
        if (timeCoffee <= (DT4 * 1000))
        {
          if (distance <= DIST2)
          {
            numCoffee++;
            if (numCoffee == NMAX)
            {
              state = 6;
              maintaince = true;
              MsgService.sendMsg("N");
            }
            else
            {
              state = 3;
            }
          }
        }
        else
        {
          numCoffee++;
          if (numCoffee == NMAX)
          {
            state = 6;
            maintaince = true;
            MsgService.sendMsg("N");
          }
          else
          {
            state = 3;
          }
        }
      }

      break;

    case 6:
      
      //Serial.println("stato MAINTAINCE");
      if (!maintaince)
      {
        if (state == 6)
        {
          state = 0;
        }
        else
        {
          //Serial.println("ERRORE");
        }
      }
      else
      {
        //Serial.println("Attendo ricarica");
      }

      break;
  }
}
