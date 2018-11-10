#include "MovementTask.h"
#include "Arduino.h"

MovementTask::MovementTask(int pin){
  this->pin = pin;
}
  
void MovementTask::init(int period){
  Task::init(period);
  pir = new PirSensorImpl(pin);    
}
  
void MovementTask::tick(){
  movement = pir->isMoved();
  /* questa operazione la può fare solo negli stati di on e stand by,
    negli altri stati non serve*/
}
