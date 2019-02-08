#include "ModeTask.h"
#include "Arduino.h"
#include "config.h"
#include "Logger.h"

ModeTask::ModeTask(SharedState *pSharedState)
{
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
  if (pSharedState->isAutoMode())
  { 
    if (pSharedState->getDistance() <= DIST && pSharedState->isConnected())
    {
      Logger.log("Manual Mode");
      pSharedState->setManualMode();
      pSharedState->setFinishPumping();
      pSharedState->setFlow(P_CLOSE);

      LM->switchOn();
      L1->switchOff();
      //Logger.log("ModeTask->Manual Mode");
    }
  }
  else
  {
    //Logger.log("Manual Mode");

    if (pSharedState->getDistance() > DIST)
    {
      Logger.log("Automathic Mode");

      pSharedState->setAutoMode();
      pSharedState->setFinishConnection();
      pSharedState->setFinishPumping();
      pSharedState->setFlow(P_CLOSE);
      Logger.log(String(pSharedState->isConnected()));
      LM->switchOff();
      L1->switchOn();
    }
  }
}
