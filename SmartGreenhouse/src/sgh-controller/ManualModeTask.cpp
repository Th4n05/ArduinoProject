#include "ManualModeTask.h"
#include "Arduino.h"
#include "config.h"
#include "MsgServiceBT.h"
#include "Logger.h"

MsgServiceBT msgServicebt(2, 3);

ManualModeTask::ManualModeTask(SharedState *pSharedState)
{
  this->pSharedState = pSharedState;


}

void ManualModeTask::init(int period)
{
  Task::init(period);

  msgServicebt.init();

}

void ManualModeTask::tick()
{
  if (pSharedState->isAutoMode() == false)
  {
    msgServicebt.sendMsg(String(pSharedState->getHumidity()));
  }
  //tutte le volte gli faccio mandare l'umidita via messaggio
  if (msgServicebt.isMsgAvailable())
  {
    Msg *msg = msgServicebt.receiveMsg();
    Logger.log(msg->getContent());
    if (msg->getContent() == "CONNESSO" && pSharedState->getDistance() < DIST)
    {
      Logger.log("Connessione in corso");
      pSharedState->setConnection();
    }

    if (pSharedState->isAutoMode() == false)
    {
      if (msg->getContent() == "APERTA")

      {

        pSharedState->setPumping();
        Logger.log("Pompa aperta");
        pSharedState->setFlow(P_MIN);
                Logger.log("Setto flow");

      }
      else if (msg->getContent() == "CHIUSA")
      {
        pSharedState->setFinishPumping();
        pSharedState->setFlow(P_CLOSE);
      }
      else // condizione chiamata se non è nessuno dei precedenti
      {
        int tempvalue = msg->getContent().toFloat() + 30;
        pSharedState->setFlow(tempvalue);
      }
    }

    if (pSharedState->getDistance() > DIST) {
      String automsg = "A";
      
      msgServicebt.sendMsg(automsg);
    }


    delete msg;
  }

}
