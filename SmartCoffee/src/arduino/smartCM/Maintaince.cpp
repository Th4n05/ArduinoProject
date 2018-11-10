#include "Task.h"
#include "MainTask.h"
#include "MsgService.h"
#include "Arduino.h"

Maintaince::Maintaince() {
  
}

void MovementTask::init(int period) {
  Task::init(period);
  MsgService.init();
}

void MovementTask::tick() {
  
}
