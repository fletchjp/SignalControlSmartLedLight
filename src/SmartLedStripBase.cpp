#include "SmartLedStripBase.h"
#include "SmartLed.h"

void SmartLedStripBase::update()
{
  for (int i=0 ; i < nLeds ; ++i)
  {
    smartLeds[i]->update(*this);
  }
  FastLED.show();
}
