#include "ModeTask.h"
#include "Arduino.h"
#include "config.h"
#include "Logger.h"


ModeTask::ModeTask(SharedState* pSharedState){
  this->pSharedState = pSharedState;
}

void ModeTask::init(int period)
{
  Task::init(period);
  this->period = period;
  this->L1 = new Led(L1_PIN);
  this->LM = new Led(LM_PIN);
  L1->switchOn();

}


void ModeTask::tick()
{
  if(pSharedState->getDistance() <= DIST && pSharedState->isConnected())
  {
    pSharedState->setManualMode();
    LM->switchOn();
    L1->switchOff();
    //Logger.log("ModeTask->Manual Mode");
  }else{
    pSharedState->setAutoMode();
    pSharedState->setFinishConnection();
    //Logger.log("ModeTask->Automatic Mode");
    LM->switchOff();
    L1->switchOn();
  }
}
