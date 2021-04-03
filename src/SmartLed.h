#pragma once

class SmartLedStripBase;
class SmartLedLight;

class SmartLed
{
  int ledIndex;
  const SmartLedLight **lights;
  int nLights;
  
public:
  SmartLed(int ledIndex, SmartLedLight & sll1)
    : ledIndex(ledIndex)
    , lights(new SmartLedLight const *[1])
    , nLights(1)
  {
    lights[0] = &sll1;
  }

  SmartLed(int ledIndex, SmartLedLight & sll1, SmartLedLight & sll2)
    : ledIndex(ledIndex)
    , lights(new SmartLedLight const *[2])
    , nLights(2)
  {
    lights[0] = &sll1;
    lights[1] = &sll2;
  }

  SmartLed(int ledIndex, SmartLedLight & sll1, SmartLedLight & sll2, SmartLedLight & sll3)
    : ledIndex(ledIndex)
    , lights(new SmartLedLight const *[3])
    , nLights(3)
  {
    lights[0] = &sll1;
    lights[1] = &sll2;
    lights[2] = &sll3;
  }

  void update(SmartLedStripBase & strip);
};
