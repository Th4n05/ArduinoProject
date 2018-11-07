#include "MakeCoffeeTask.h"
#include "Arduino.h"

MakeCoffeeTask::MakeCoffeeTask(int pin0, int pin1, int pin2){
  this->pin[0] = pin0;    
  this->pin[1] = pin1;    
  this->pin[2] = pin2;    
}
  
void MakeCoffeeTask::init(int period){
  Task::init(period);
  for (int i = 0; i < 3; i++){
    led[i] = new Led(pin[i]); 
  }
  num = 0;    
}
  
void MakeCoffeeTask::tick(){
  /*aggiugnere avvio solo se è il mio turno*/
  led[num]->switchOff();
  num = (num + 1) % 3;
  led[num]->switchOn();
  delayMicroseconds(10000);
}
