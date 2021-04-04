#include <FastLED.h>
#include "SmartLedStripBase.h"

template<int controlPin, EOrder RGB_ORDER = GRB> 
class SK6812Strip : public SmartLedStripBase
{
public:
  SK6812Strip(SmartLed & sl1)
    : SmartLedStripBase(sl1)
  {
    FastLED.addLeds<SK6812, controlPin, RGB_ORDER>(leds, nLeds);
  }

  SK6812Strip(SmartLed & sl1, SmartLed & sl2)
    : SmartLedStripBase(sl1, sl2)
  {
    FastLED.addLeds<SK6812, controlPin, RGB_ORDER>(leds, nLeds);
  }
};
