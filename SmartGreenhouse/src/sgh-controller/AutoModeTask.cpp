#include "AutoModeTask.h"
#include "Arduino.h"
#include "config.h"
#include "Logger.h"
#include "ErrorSender.h"
#include "IrrigationSender.h"



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
  this->period = period;
}

void AutoModeTask::tick()
{

  if (pSharedState->isAutoMode())
  {
    switch (state)
    {
    case IDLE:
      //Logger.log("AutoModeTask->Idle");
      if (pSharedState->getHumidity() < U_MIN)
      {
        state = CHOOSE;
        
      }
      break;

    case CHOOSE:
      Logger.log("AutoModeTask->State Choosen");
      if (pSharedState->getFlow() == P_CLOSE)
      {
        if (pSharedState->getHumidity() <= 30 && pSharedState->getHumidity() > 20)
        {
          pSharedState->setFlow(P_MIN);
          Logger.log("AutoModeTask->SetFLow PMIN");
          state = WAIT;
          L2->switchOn();
        }
        else if (pSharedState->getHumidity() <= 20 && pSharedState->getHumidity() > 10)
        {
          pSharedState->setFlow(P_MED);
          Logger.log("AutoModeTask->SetFLow PMED");
          state = WAIT;
          L2->switchOn();
        }
        else if (pSharedState->getHumidity() <= 10 && pSharedState->getHumidity() >= 0)
        {
          pSharedState->setFlow(P_MAX);
          Logger.log("AutoModeTask->SetFLow PMAX");
          state = WAIT;
          L2->switchOn();
        }
      }
      break;

    case WAIT:
      Logger.log("AutoModeTask->Wait");
      erogationTime += period;
      if (pSharedState->getHumidity() > (U_MIN + DELTA_U))
      {
        state = IDLE;
        pSharedState->setFlow(P_CLOSE);
        int temp_time = erogationTime / 1000;
        IrrigationSender.sendInfo(String(temp_time));
        erogationTime = 0;
        L2->switchOff();
      }
      if (erogationTime > T_MAX)
      {
        state = ERROR;
       
        pSharedState->setFlow(P_CLOSE);
        IrrigationSender.sendInfo("5");
        erogationTime = 0;
        L2->switchOff();
      }
      break;

    case ERROR:
      Logger.log("AutoModeTask->Error");
      // QUI BISOGNA MANDARE LA SEGNALAZIONE DELL'ERRORE
      ErrorSender.send("Tempo Massimo Apertura Pompa Superato");
      state = IDLE;
      
      break;
    }
  }else{
    L2->switchOff();
  }
}
