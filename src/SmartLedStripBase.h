#include "FastLED.h"

class SmartLed;

class SmartLedStripBase 
{
protected:
  SmartLed ** smartLeds;
  int nSmartLeds = 0;
  CRGB * leds;
  int nLeds;

  SmartLedStripBase(int nLeds);

public:
  void add(SmartLed * smartLed)
  {
    // TODO: Protect agains adding more LEDs than nLeds.
    smartLeds[nSmartLeds++] = smartLed;
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
