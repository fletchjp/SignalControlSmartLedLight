#include <FastLED.h>
#include "SmartLedStripBase.h"

template<int controlPin, EOrder RGB_ORDER = GRB> 
class SK6812Strip : public SmartLedStripBase
{
public:
  SK6812Strip(int nLeds_)
    : SmartLedStripBase(nLeds_)
  {
    FastLED.addLeds<SK6812, controlPin, RGB_ORDER>(leds, nLeds);
  }
};
