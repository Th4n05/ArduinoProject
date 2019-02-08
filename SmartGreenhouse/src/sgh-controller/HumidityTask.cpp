#include "HumidityTask.h"
#include "Arduino.h"
#include "MsgService.h"
#include "Logger.h"

HumidityTask::HumidityTask( SharedState* pSharedState )
{
  this->pSharedState = pSharedState;
}

void HumidityTask::init(int period)
{
  Task::init(period);
}

void HumidityTask::tick()
{
  if (MsgService.isMsgAvailable())
  {
    Msg *msg = MsgService.receiveMsg();
    //Logger.log(msg->getContent());
    pSharedState->setHumidity(msg->getContent().toFloat());
    delete msg;
  }
}
