#pragma once

#include "SmartLedStripBase.h"
#include "SmartLed.h"

template <class Controller, int controlPin>
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
    FastLED.addLeds<Controller, controlPin>(leds, nLeds);
  }

  SmartLedStrip(SmartLed & sl1, SmartLed & sl2)
    : smartLeds(new SmartLed*[2])
    , leds(new CRGB[2])
    , nLeds(2)
  {
    smartLeds[0] = &sl1;
    smartLeds[1] = &sl2;
    FastLED.addLeds<Controller, controlPin>(leds, nLeds);
  }

  virtual void setLed(int ledIndex, CRGB::HTMLColorCode color) override
  {
    leds[ledIndex] = color;
  }

  virtual void update() override;
};

template <class Controller, int controlPin>
void SmartLedStrip<Controller, controlPin>::update()
{
  for (int i=0 ; i < nLeds ; ++i)
  {
    smartLeds[i]->update(*this);
  }
  FastLED.show();
}
