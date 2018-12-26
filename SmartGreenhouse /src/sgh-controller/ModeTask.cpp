#include "ModeTask.h"
#include "Arduino.h"
#include "DistanceTask.h"


const float DIST1 = 0.3;


MainTask::MainTask(){}

void MainTask::init(int period)
{
  Task::init(period);
  this->period = period;

}


void MainTask::tick()
{
  if(distance <= DIST1)
  {
    manualMode = true;
  }else{
    manualMode = false;
  }
}
