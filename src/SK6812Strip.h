#include <FastLED.h>
#include "SmartLedStrip.h"

template<int controlPin, EOrder RGB_ORDER = GRB> 
class SK6812Strip : public SmartLedStrip<SK6812, controlPin, RGB_ORDER>
{
public:
  using SmartLedStrip<SK6812, controlPin, RGB_ORDER>::SmartLedStrip;
};
