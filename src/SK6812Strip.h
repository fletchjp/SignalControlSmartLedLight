#include <FastLED.h>
#include "SmartLedStripBase.h"

template<int controlPin, EOrder RGB_ORDER = GRB> 
class SK6812Strip : public SmartLedStripBase
{
public:
  using SmartLedStripBase::SmartLedStripBase;

  void addLeds(CRGB leds[], int nLeds) override
  {
    FastLED.addLeds<SK6812, controlPin, RGB_ORDER>(leds, nLeds);
  }
};
