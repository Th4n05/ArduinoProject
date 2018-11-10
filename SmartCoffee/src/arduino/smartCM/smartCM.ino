#include "Scheduler.h"
#include "MakeCoffeeTask.h"
#include "MovementTask.h"
#include "DistanceTask.h"



Scheduler sched;

void setup(){
  
  sched.init(50);
  
  /*Task* t0 = new MainTask(2);
  t0->init(50);// da vedere se va bene come periodo
  sched.addTask(t0);*/


  /*Task* t1 = new MakeCoffeeTask(11,12,13);
  t1->init(150);
  sched.addTask(t1); */ 

  /*Task* t2 = new MovementTask(4);
  t2->init(50);
  sched.addTask(t2); */

  Task* t3 = new DistanceTask(7, 8);
  t3->init(100);
  sched.addTask(t3);
    
}

void loop(){
  sched.schedule();
}
