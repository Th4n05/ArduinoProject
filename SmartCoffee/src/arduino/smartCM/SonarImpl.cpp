#include "SonarImpl.h"
#include "Arduino.h"
const float vs = 331.5 + 0.6 * 20;


SonarImpl::SonarImpl(int trig, int echo)
{
  this->trigPin = trig;
  this->echoPin = echo;
  this->alpha = 0.7;
  this->averageDistance = -1; // valore iniziale
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float SonarImpl::getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  /* ricevi l’eco */
  float tUS = pulseIn(echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float dist = t * vs;
  if (averageDistance == -1) {
    averageDistance = dist;
  } else {
    averageDistance = (averageDistance * alpha) + (dist * (1 - alpha)); // media pesata per dare più peso ai vecchi dati e meno ai nuovi
  }
  return averageDistance;
}
