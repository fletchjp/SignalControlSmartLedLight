#include <FastLED.h>
#include "SmartLedStrip.h"

template<int controlPin>
class NeoPixelStrip : public SmartLedStrip<NEOPIXEL, controlPin>
{
public:
  using SmartLedStrip<NEOPIXEL, controlPin>::SmartLedStrip;
};
