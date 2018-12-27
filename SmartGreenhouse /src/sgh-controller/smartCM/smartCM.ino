#include "Scheduler.h"
#include "MakeCoffeeTask.h"
#include "DistanceTask.h"
#include "MovementTask.h"
#include "ModeTask.h"
#include "MaintainceTask.h"



bool manualMode;
bool irrigation;
float humidity;


Scheduler sched;

void setup()
{

  Serial.begin(9600);
  sched.init(50);

  Task *t0 = new ModeTask(2);
  t0->init(150); // da vedere se va bene come periodo
  sched.addTask(t0);

  Task *t1 = new MakeCoffeeTask(10, 11, 12);
  t1->init(100);
  sched.addTask(t1);

  Task *t2 = new MovementTask(3);
  t2->init(50);
  sched.addTask(t2);

  Task *t3 = new DistanceTask(7, 8);
  t3->init(50);
  sched.addTask(t3);

  Task *t4 = new MaintainceTask();
  t4->init(100); // da vedere se va bene come periodo
  sched.addTask(t4);
}

void loop()
{
  sched.schedule();
}
