#include "DistanceTask.h"
#include "Arduino.h"

DistanceTask::DistanceTask(int trig, int echo){
  this->echoPin = echo;    
  this->trigPin = trig;    
}
  
void DistanceTask::init(int period){
  Task::init(period);
  sonar = new SonarImpl(trigPin, echoPin);
}
  
void DistanceTask::tick(){
  distance = sonar->getDistance();  
}
