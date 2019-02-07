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
    if (pSharedState->getDistance() > DIST)
    {
      pSharedState->setAutoMode();
      pSharedState->setFinishConnection();
      pSharedState->setFinishPumping();
      pSharedState->setFlow(P_CLOSE);
      //Logger.log("ModeTask->Automatic Mode");
      LM->switchOff();
      L1->switchOn();
    }
  }
}
