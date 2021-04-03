#pragma once

#include "FastLED.h"

class SmartLed;

class SmartLedStripBase
{
public:
  void setBrightness(uint8_t scale)
  {
    FastLED.setBrightness(scale);
  }

  void setTemperature(const struct CRGB & temp)
  {
    FastLED.setTemperature(temp);
  }

  virtual void setLed(int ledIndex, CRGB::HTMLColorCode color) = 0;

  virtual void update() = 0;
};
