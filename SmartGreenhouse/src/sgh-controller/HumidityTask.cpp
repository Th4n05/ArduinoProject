#include "HumidityTask.h"
#include "Arduino.h"
#include "MsgService.h"

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
    pSharedState->setHumidity(msg->getContent().toFloat());
    delete msg;
  }
}
