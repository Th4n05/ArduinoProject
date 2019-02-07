#include "DistanceTask.h"
#include "Arduino.h"

DistanceTask::DistanceTask( SharedState* pSharedState ,int echo, int trig){
  this->pSharedState = pSharedState;
  this->echoPin = echo;    
  this->trigPin = trig;    
}
  
void DistanceTask::init(int period){
  Task::init(period);
  sonar = new SonarImpl(trigPin, echoPin);
}
  
void DistanceTask::tick(){
  pSharedState->setDistance(sonar->getDistance());  
}
