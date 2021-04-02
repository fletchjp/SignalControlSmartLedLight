#include <FastLED.h>
#include "SmartLedStripBase.h"

template<int controlPin>
class NeoPixelStrip : public SmartLedStripBase
{
public:
  using SmartLedStripBase::SmartLedStripBase;

protected:
  // TODO: Need to call this after construction
  // There are a few possiblities:
  // 1) User calls init() when created. Error prone as this must be called from setup() which is far away from object definition.
  // 2) Pass a static function pointer to base class ctor. That means we cannot use "using" for base constructors.
  // 3) Use a static create function that calls the constructor as is today followed by init() as in 1) above.
  void addLeds(CRGB leds[], int nLeds) override
  {
    FastLED.addLeds<NEOPIXEL, controlPin>(leds, nLeds);
  }
};
