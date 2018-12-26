#include "HumidityTask.h"
#include "Arduino.h"

HumidityTask::HumidityTask(int trig, int echo){
  this->pin = pin;    
}
  
void HumidityTask::init(int period){
  Task::init(period);
  humSensor = new HumiditySensorImpl(this->pin);
}
  
void HumidityTask::tick(){
  humidity = humSensor->getValue();  
}
