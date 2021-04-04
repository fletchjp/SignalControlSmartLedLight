#pragma once

#include "FastLED.h"

class SmartLed;

class SmartLedStripBase
{
protected:
  SmartLed ** smartLeds;
  CRGB * leds;
  int nLeds;

public:
  SmartLedStripBase(SmartLed & sl1)
    : smartLeds(new SmartLed*[1])
    , leds(new CRGB[1])
    , nLeds(1)
  {
    smartLeds[0] = &sl1;
  }

  SmartLedStripBase(SmartLed & sl1, SmartLed & sl2)
    : smartLeds(new SmartLed*[2])
    , leds(new CRGB[2])
    , nLeds(2)
  {
    smartLeds[0] = &sl1;
    smartLeds[1] = &sl2;
  }

  void setBrightness(uint8_t scale)
  {
    FastLED.setBrightness(scale);
  }

  void setTemperature(const struct CRGB & temp)
  {
    FastLED.setTemperature(temp);
  }

  void setLed(int ledIndex, CRGB::HTMLColorCode color)
  {
    leds[ledIndex] = color;
  }

  void update();
};
