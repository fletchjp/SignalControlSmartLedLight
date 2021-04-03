#include "SmartLedStrip.h"

void SmartLedStrip::update()
{
  for (int i=0 ; i < nLeds ; ++i)
  {
    smartLeds[i]->update(*this);
  }
  FastLED.show();
}
