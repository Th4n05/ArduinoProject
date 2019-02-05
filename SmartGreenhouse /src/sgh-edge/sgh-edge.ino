#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "HumiditySensorImpl.h"
#define PIN D4

/* wifi network name */
char* ssidName = "iPhone di Enrico";
/* WPA2 PSK password */
char* pwd = "8au14zwz2cqzb";
/* service IP address */ 
char* address = "http://f2a148bc.ngrok.io";
HumiditySensorImpl* humSensor;


void setup() { 
  Serial.begin(115200);                                
  WiFi.begin(ssidName, pwd);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);
    Serial.print(".");
  } 
  Serial.println("Connected: \n local IP: "+WiFi.localIP());
  humSensor = new HumiditySensorImpl(PIN);
}

int sendData(String address, float value, String place){  
   HTTPClient http;    
   http.begin(address + "/api/data");      
   http.addHeader("Content-Type", "application/json");     
   String msg = 
    String("{ \"value\": ") + String(value) + 
    ", \"place\": \"" + place +"\" }";
   int retCode = http.POST(msg);   
   http.end();  
      
   // String payload = http.getString();  
   // Serial.println(payload);      
   return retCode;
}
   
void loop() { 
 if (WiFi.status()== WL_CONNECTED){   

   /* read sensor */
   float value = humSensor->getValue();
   
   /* send data */
   Serial.print("sending humidity:  "+String(value)+"%   ");    
   int code = sendData(address, value, "home");

   /* log result */
   if (code == 200){
     Serial.println("ok");   
   } else {
     Serial.println("error");
   }
 } else { 
   Serial.println("Error in WiFi connection");   
 }
 
 delay(5000);  
 
}
