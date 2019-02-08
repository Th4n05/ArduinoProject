#ifndef __ERRORSENDER__
#define __ERRORSENDER__

#include "Arduino.h"


class ErrorService {
    
public: 
  
  void send(const String& msg);
};

extern ErrorService ErrorSender;

#endif
