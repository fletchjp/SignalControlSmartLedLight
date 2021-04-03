#pragma once

#include "SmartLedStripBase.h"
#include "SmartLed.h"

class SmartLedStrip : public SmartLedStripBase
{
protected:
  SmartLed ** smartLeds;
  CRGB * leds;
  int nLeds;

public:
  SmartLedStrip(SmartLed & sl1)
    : smartLeds(new SmartLed*[1])
    , leds(new CRGB[1])
    , nLeds(1)
  {
    smartLeds[0] = &sl1;
  }

  SmartLedStrip(SmartLed & sl1, SmartLed & sl2)
    : smartLeds(new SmartLed*[2])
    , leds(new CRGB[2])
    , nLeds(2)
  {
    smartLeds[0] = &sl1;
    smartLeds[1] = &sl2;
  }

  virtual void setLed(int ledIndex, CRGB::HTMLColorCode color) override
  {
    leds[ledIndex] = color;
  }

  virtual void update() override;
};
