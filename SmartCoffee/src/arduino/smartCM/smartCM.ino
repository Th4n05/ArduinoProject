#include "Scheduler.h"
#include "MakeCoffeeTask.h"
#include "DistanceTask.h"
#include "MovementTask.h"
#include "MainTask.h"


bool movement;
float distance;
bool makeCoffee;
int numCoffee;
int state;


Scheduler sched;

void setup() {

  Serial.begin(9600);
  sched.init(50);

  Task* t0 = new MainTask(2);
  t0->init(200);// da vedere se va bene come periodo
  sched.addTask(t0);

  makeCoffee = true;
  Task* t1 = new MakeCoffeeTask(10, 11, 12);
  t1->init(100);
  sched.addTask(t1);
  
  Task* t2 = new MovementTask(9);
  t2->init(150);
  sched.addTask(t2);
  
 Task* t3 = new DistanceTask(7, 8);
  t3->init(200);
  sched.addTask(t3);

}

void loop() {
  sched.schedule();
}
