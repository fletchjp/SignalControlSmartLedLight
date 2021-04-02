#include "SmartLedStripBase.h"
#include "SmartLed.h"
#include "SmartLedLight.h"

void SmartLed::update(SmartLedStripBase & strip)
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
