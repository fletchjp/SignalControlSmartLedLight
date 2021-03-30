#include "SmartLedStripBase.h"
#include "SmartLed.h"
#include "SmartLedLight.h"

SmartLed::SmartLed(SmartLedStripBase & strip, int ledIndex)
  : strip(strip)
  , ledIndex(ledIndex)
{
  strip.add(this);
}

void SmartLed::update()
{
  for (int i = 0 ; i < nLights ; ++i)
  {
    if (lights[i]->get())
    {
      strip.setLed(ledIndex, lights[i]->getColor());
      return;
    }
  }
  // No signal lights are set, use black
  strip.setLed(ledIndex, CRGB::Black);
}
