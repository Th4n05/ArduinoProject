#include "Task.h"
#include "MainTask.h"
#include "MsgService.h"
#include "Arduino.h"
#include "MakeCoffe.h"

#define NUMRECHARGE 10;

extern int numCoffee;

Maintaince::Maintaince() {

}

void Maintaince::init(int period) {
  Task::init(period);
  MsgService.init();
}

void Maintaince::tick() {
  if(state==6)){
    if (MsgService.isMsgAvailable()) {
      Msg* msg = MsgService.receiveMsg();
      if(numeCoffee < NUMRECHARGE){
        if (msg->getContent() == "ok"){
          numCoffee = NUMRECHARGE;
        }
      }
      delete msg;
    }
  }
}
