#include "Led.h"
#include "Arduino.h"

Led::Led(int pin){
  this->pin = pin;
  pinMode(pin,OUTPUT);
}

void Led::switchOn(){
  digitalWrite(pin,HIGH);
}

void Led::switchOff(){
  digitalWrite(pin,LOW);
};





#define LED_PIN 10

int brightness;
int fadeAmount;
int currIntensity;

void setup(){
  currIntensity = 0;
  fadeAmount = 5;
  pinMode(LED_PIN, OUTPUT);     
}

void loop(){
  analogWrite(LED_PIN, currIntensity);   
  currIntensity = currIntensity + fadeAmount;
  if (currIntensity == 0 || currIntensity == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  delay(15);                               
}