#include "ErrorSender.h"
#include "MsgService.h"

void ErrorService::send(const String& msg){
  MsgService.sendMsg("er:"+msg);
}


