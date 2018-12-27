#ifndef __HUMIDITYSENSORIMPL__
#define __HUMIDITYSENSORIMPL__

#include "HumiditySensor.h"
#include "DHT.h"

class HumiditySensorImpl : public HumiditySensor {
 
public: 
  HumiditySensorImpl(int pin);
  float getValue();

private:
  int hPin;
};

#endif
