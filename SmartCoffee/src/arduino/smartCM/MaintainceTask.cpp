#include "MaintainceTask.h"
#include "Arduino.h"
#include "MsgService.h"

MaintainceTask::MaintainceTask()
{
}

void MaintainceTask::init(int period)
{
    Task::init(period);
    int NC = 0;
}

void MaintainceTask::tick()
{
    if (maintaince)
    {
        if (MsgService.isMsgAvailable())
        {
            Msg *msg = MsgService.receiveMsg();
            NC = msg->getContent();
            numCoffee += NC;
            MsgService.sendMsg("Coffee refilled: %d", NC);
            delete msg;
            maintaince = false;
        }
    }
}
