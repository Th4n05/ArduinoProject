#include "MainTask.h"
#include "Arduino.h"

const float DIST1 = 0.3;
const float DIST2 = 0.1;
const int DT1 = 1;
const int DT2a = 5;
const int DT2b = 5;
const int DT3 = 3;
const int DT4 = 5;


MainTask::MainTask()
{
}


void MainTask::init(int period)
{
  Task::init(period);
  state = STANBY;
  timeStandby=0;
  timeReady=0;
  timerOn=0;
  

}

void MainTask::tick()
{
  switch(state){
    case STANDBY:
      if(movement){
        state = ON;
      }
    break;

    case ON:
      
    break;

    case READY:
      
    break;

    case MAKECOFFEE:
     
    break;

    case MAINTAINCE:
      
    break;
  }
}
