#include "AutoModeTask.h"

#include "Arduino.h"
#include "Led.h"

const float UMIN = 30; 

AutoModeTask::AutoModeTask(int pin){
  this->ledPin = pin;
}
  
void AutoModeTask::init(int period){
  Task::init(period);
  L1 = new Led(ledPin);
  L1->switchOff();

}
  
void IrrigationTask::tick(){
  //qui posso mettere o direttamente l'implementazione del sensore di umidità
  //o posso creare un task apposta per settare humidity e poi quella variabile viene letta da questo task come tutte le altre e ha più senso
  if(!manualMode){
    L1->switchOn();
    if(humidity < UMIN){
      irrigation=true;
    }
  }

}
