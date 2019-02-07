#include "ManualModeTask.h"
#include "Arduino.h"
#include "config.h"
#include "MsgServiceBT.h"

ManualModeTask::ManualModeTask(SharedState *pSharedState)
{
    this->pSharedState = pSharedState;
    
}

void ManualModeTask::init(int period)
{
    Task::init(period);
    
}

void ManualModeTask::tick()
{
    MsgServiceBT msgServicebt(2, 3);
    msgServicebt.init();
    //tutte le volte gli faccio mandare l'umidita via messaggio
    msgServicebt.sendMsg(String(pSharedState->getHumidity()));
    if (msgServicebt.isMsgAvailable())
    {
        Msg *msg = msgServicebt.receiveMsg();
        if (msg->getContent() == "Connection")
        {
            pSharedState->setConnection();
        }
        else
        {
            if (!pSharedState->isAutoMode())
            {
                if (msg->getContent() == "Open")
                {
                    pSharedState->setPumping();
                   pSharedState->setFlow(P_MIN); 
                }
                else if (msg->getContent() == "Closed")
                {
                    pSharedState->setFinishPumping();
                   pSharedState->setFlow(P_CLOSE); 
                }
                else // condizione chiamata se non è nessuno dei precedenti
                {
                    pSharedState->setFlow(msg->getContent().toFloat()); 
                }
            }
        }

        delete msg;
    }

}
