#ifndef __SHARED_STATE__
#define __SHARED_STATE__

class SharedState
{

private:
  bool autoMode;
  bool btConnection;
  int flow;
  float distance;
  float humidity;
  bool pumping;

public:
  SharedState()
  {
    autoMode = true;
    btConnection = false;
    flow = 30;
    distance = 0;
    humidity = 25;
    pumping = false;
  }

  bool isAutoMode() { return autoMode; }
  void setAutoMode() { autoMode = true; }
  void setManualMode() { autoMode = false; }

  bool isConnected() { return btConnection; }
  void setConnection() { btConnection = true; }
  void setFinishConnection() { btConnection = false; }

  int getFlow() { return flow; }
  void setFlow(int value) { flow = value; }

  float getHumidity() { return humidity; }
  void setHumidity(float value) { humidity = value; }

  float getDistance() { return distance; }
  void setDistance(float value) { distance = value; }

  bool isPumping() { return pumping; }
  void setPumping() { pumping = true; }
  void setFinishPumping() { pumping = false; }
};

#endif
