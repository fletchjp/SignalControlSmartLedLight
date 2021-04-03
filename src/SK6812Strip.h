#include <FastLED.h>
#include "SmartLedStrip.h"

template<int controlPin, EOrder RGB_ORDER = GRB> 
class SK6812Strip : public SmartLedStrip
{
public:
  SK6812Strip(SmartLed & sl1)
    : SmartLedStrip(sl1)
  {
    FastLED.addLeds<SK6812, controlPin, RGB_ORDER>(leds, nLeds);
  }

  SK6812Strip(SmartLed & sl1, SmartLed & sl2)
    : SmartLedStrip(sl1, sl2)
  {
    FastLED.addLeds<SK6812, controlPin, RGB_ORDER>(leds, nLeds);
  }
};
