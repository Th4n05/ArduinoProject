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
    if (msg->getContent() == "CONNESSO")
    {
      Logger.log("Connessione in corso");
      pSharedState->setConnection();
    }

    if (pSharedState->isAutoMode() == false)
    {
      if (msg->getContent() == "APERTO")

      {

        pSharedState->setPumping();
        pSharedState->setFlow(P_MIN);
      }
      else if (msg->getContent() == "CHIUSO")
      {
        pSharedState->setFinishPumping();
        pSharedState->setFlow(P_CLOSE);
      }
      else // condizione chiamata se non è nessuno dei precedenti
      {
        pSharedState->setFlow(msg->getContent().toFloat());
      }
    }


    delete msg;
  }

}
