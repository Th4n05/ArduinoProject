#include "SonarImpl.h"
#include "Arduino.h"
const float vs = 331.5 + 0.6*20;


SonarImpl::SonarImpl(int trig, int echo)
{
    this->trigPin = trig;
    this->echoPin = echo;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float SonarImpl::getDistance()
{
    digitalWrite(trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);
    /* ricevi l’eco */
    float tUS = pulseIn(echoPin, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    float dist = t*vs;
    return dist;
}
