#include "HumiditySensorImpl.h"
#include "Arduino.h"
#include <dht.h>

HumiditySensorImpl::HumiditySensorImpl(int pin)
{
    this->hPin = pin;
}

int HumiditySensorImpl::getValue()
{
    int readData = DHT.read22(hPin); // Reads the data from the sensor
    return DHT.humidity; 
}
