#include <FastLED.h>
#include "SmartLedStrip.h"

template<int controlPin>
class NeoPixelStrip : public SmartLedStrip
{
public:
  NeoPixelStrip(SmartLed & sl1)
    : SmartLedStrip(sl1)
  {
    FastLED.addLeds<NEOPIXEL, controlPin>(leds, nLeds);
  }

  NeoPixelStrip(SmartLed & sl1, SmartLed & sl2)
    : SmartLedStrip(sl1, sl2)
  {
    FastLED.addLeds<NEOPIXEL, controlPin>(leds, nLeds);
  }
};
