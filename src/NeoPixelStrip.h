#include <FastLED.h>
#include "SmartLedStripBase.h"

template<int controlPin>
class NeoPixelStrip : public SmartLedStripBase
{
public:
  NeoPixelStrip(int nLeds_)
    : SmartLedStripBase(nLeds_)
  {
    FastLED.addLeds<NEOPIXEL, controlPin>(leds, nLeds);
  }
};
