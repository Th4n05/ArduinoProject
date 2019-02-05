#include "AutoModeTask.h"
#include "Arduino.h"
#include "config.h"
#include "Logger.h"

AutoModeTask::AutoModeTask(SharedState *pSharedState)
{
  this->pSharedState = pSharedState;
}

void AutoModeTask::init(int period)
{
  Task::init(period);
  L2 = new Led(L2_PIN);
  L2->switchOff();
  erogationTime = 0;
  state = IDLE;
}

void AutoModeTask::tick()
{
  if (pSharedState->isAutoMode)
  {

    if (pSharedState->getHumidity() < U_MIN && state == IDLE)
    {
      state = CHOOSE;
      Logger.log("AutoModeTask->State Choosen");

    }

    if (state == CHOOSE && pSharedState->getFlow() == 0)
    {
      if (pSharedState->getHumidity() <= 30 && pSharedState->getHumidity() > 20)
      {
        pSharedState->setFlow(P_MIN);
      }
      else if (pSharedState->getHumidity() <= 20 && pSharedState->getHumidity() > 10)
      {
        pSharedState->setFlow(P_MED);
      }
      else if (pSharedState->getHumidity() <= 10 && pSharedState->getHumidity() >= 0)
      {
        pSharedState->setFlow(P_MAX);
      }
      else
      {
        // qui si potrebbe aggiungere una segnalazione di malfunzionamento del sensore
      }
      state = WAIT;
      Logger.log("AutoModeTask->Wait");
      L2->switchOn();
    }

    if (state == WAIT)
    {
      erogationTime += period;
      if (pSharedState->getHumidity() > (U_MIN + DELTA_U))
      {
        state = IDLE;
        pSharedState->setFlow(0);
        Logger.log("ModeTask->Idle");
        erogationTime = 0;
        L2->switchOff();
      }
      if (erogationTime > T_MAX)
      {
        state = ERROR;
        Logger.log("ModeTask->Error");
        pSharedState->setFlow(0);
        erogationTime = 0;
        L2->switchOff();
      }
    }

    if (state == ERROR)
    {
      // QUI BISOGNA MANDARE LA SEGNALAZIONE DELL'ERRORE
      state = IDLE;
      Logger.log("ModeTask->Idle");
    }
  }
}
}