#ifndef __SUGARREGULATORIMPL__
#define __SUGARREGULATORIMPL__

#include "SugarRegulator.h"

class SugarRegulatorImpl : public SugarRegulator {
 
public: 
  SugarRegulatorImpl(int pin);
  int getSugar();

private:
  int pin;

};

#endif