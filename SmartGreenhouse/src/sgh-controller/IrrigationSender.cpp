#include "IrrigationSender.h"
#include "MsgService.h"

void IrrigationService::sendInfo(const String& msg){
  MsgService.sendMsg("ir:"+msg);
}
