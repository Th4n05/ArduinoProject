#ifndef __SHARED_STATE__
#define __SHARED_STATE__

class SharedState
{

private:
  bool autoMode;
  bool btConnection;
  float flow;
  float distance;
  float humdity;
  bool pumping;

public:
  SharedState()
  {
    autoMode = true;
    btConnection = false;
    flow = 0;
    distance = 0;
    humdity = 0;
    pumping = false;
  }

  bool isAutoMode() { return autoMode; }
  void setAutoMode() { autoMode = true; }
  void setManualMode() { autoMode = false; }

  bool isConnected() { return btConnection; }
  void setConnection() { btConnection = true; }
  void setFinishConnection() { btConnection = false; }

  float getFlow() { return flow; }
  void setFlow(float value) { flow = value; }

  float getHumidity() { return flow; }
  void setHumidity(float value) { humdity = value; }

  float getDistance() { return distance; }
  void setDistance(float value) { distance = value; }

  bool isPumping() { return pumping; }
  void setPumping() { pumping = true; }
  void setFinishPumping() { pumping = false; }
};

#endif
