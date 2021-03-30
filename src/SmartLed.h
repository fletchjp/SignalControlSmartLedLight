
class SmartLedStripBase;
class SmartLedLight;

class SmartLed
{
  SmartLedStripBase & strip;
  int ledIndex;
  const SmartLedLight *lights[3]; // Max 3 pointers to lights that control this LED.
  int nLights = 0;
  
public:
  SmartLed(SmartLedStripBase & strip, int ledIndex);

  void add(SmartLedLight const * light)
  {
    // TODO: Protect against too many lights added.
    lights[nLights++] = light;
  }

  void update();
};
