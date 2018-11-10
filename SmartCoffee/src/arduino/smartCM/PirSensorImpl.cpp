#include "PirSensorImpl.h"
#include "Arduino.h"

PirSensorImpl::PirSensorImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);     
} 
  
bool PirSensorImpl::isMoved(){
  return (digitalRead(pin) == HIGH);
}
