#include "PirSensorImpl.h"
#include "Arduino.h"

PirSensorImpl::PirSensorImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);    
  //delay(2000); // non so se va bene
} 
  
bool PirSensorImpl::isMoved(){
  //return (digitalRead(pin) == HIGH);
  return true;
}
