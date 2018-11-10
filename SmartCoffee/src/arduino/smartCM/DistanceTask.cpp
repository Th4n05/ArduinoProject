#include "DistanceTask.h"
#include "Arduino.h"

DistanceTask::DistanceTask(int trig, int echo){
  this->echoPin = echo;    
  this->trigPin = trig;    
}
  
void DistanceTask::init(int period){
  Task::init(period);
  sonar = new SonarImpl(trigPin, echoPin);
  Serial.begin(9600);
}
  
void DistanceTask::tick(){
  Serial.println(sonar->getDistance());
  
}
