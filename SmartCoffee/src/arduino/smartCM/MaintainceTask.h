#ifndef __MAINTAINCETASK__
#define __MAINTAINCETASK__

#include "Task.h"
#include "MsgService.h"

extern bool maintaince;


class MaintainceTask: public Task {


  public:

    MaintainceTask();
    void init(int period);
    void tick();
};

#endif
