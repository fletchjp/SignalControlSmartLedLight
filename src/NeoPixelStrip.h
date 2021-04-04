#include <FastLED.h>
#include "SmartLedStripBase.h"

template<int controlPin>
class NeoPixelStrip : public SmartLedStripBase
{
public:
  NeoPixelStrip(SmartLed & sl1)
    : SmartLedStripBase(sl1)
  {
    FastLED.addLeds<NEOPIXEL, controlPin>(leds, nLeds);
  }

  NeoPixelStrip(SmartLed & sl1, SmartLed & sl2)
    : SmartLedStripBase(sl1, sl2)
  {
    FastLED.addLeds<NEOPIXEL, controlPin>(leds, nLeds);
  }
};
