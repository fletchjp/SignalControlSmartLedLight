#include "SmartLedStripBase.h"
#include "SmartLed.h"

SmartLedStripBase::SmartLedStripBase(int nLeds_)
  : smartLeds(new SmartLed*[nLeds_])
  , leds(new CRGB[nLeds_])
  , nLeds(nLeds_)
{}
  
void SmartLedStripBase::update()
{
  for (int i=0 ; i < nSmartLeds ; ++i)
  {
    smartLeds[i]->update();
  }
  FastLED.show();
}
