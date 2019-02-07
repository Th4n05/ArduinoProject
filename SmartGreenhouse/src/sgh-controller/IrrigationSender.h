#ifndef __IRRIGATIONSENDER__
#define __IRRIGATIONSENDER__

#include "Arduino.h"


class IrrigationService {
    
public: 
  
  void sendInfo(const String& msg);
};

extern IrrigationService IrrigationSender;

#endif
