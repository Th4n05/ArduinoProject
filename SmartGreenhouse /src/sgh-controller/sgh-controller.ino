#include "Scheduler.h"
#include "config.h"
#include "MsgService.h"
#include "DistanceTask.h"
#include "ModeTask.h"

Scheduler sched;
SharedState *pSharedState = new SharedState();

void setup()
{

  sched.init(50);

  MsgService.init();

  /*PresenceSensor* pPres = new Pir(PRES_PIN);
    ProximitySensor* pProx = new Sonar(PROX_ECHO_PIN, PROX_TRIG_PIN);
    Potentiometer* pPot = new Potentiometer(A0);
    Button* pButtonT1 = new ButtonImpl(T1_PIN);
    ProgressBar* pBar = new ProgressBar(new LedExt(L1_PIN), new LedExt(L2_PIN), new LedExt(L3_PIN));
    UserConsole* pUserConsole = new UserConsole();

    /* used for testing  */
  // pSharedState->setModalityReady();
  // pSharedState->setMaintenance();

  Task *t0 = new DistanceTask(pSharedState, PROX_ECHO_PIN, PROX_TRIG_PIN);
  t0->init(50);
  sched.addTask(t0);

  Task *t1 = new ModeTask(pSharedState);
  t1->init(50);
  sched.addTask(t1);

  Task *t2 = new AutoModeTask(pSharedState);
  t2->init(50);
  sched.addTask(t2);

  /*Task *t3 = new ManageSugarTask(pSharedState, pPot, pUserConsole);
    t3->init(100);
    sched.addTask(t3);*/
}

void loop()
{
  sched.schedule();
  MsgService.sendMsg(String(pSharedState->isAutoMode()));
}
