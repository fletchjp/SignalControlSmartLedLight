#include <NeoPixelStrip.h>
#include <SmartLed.h>
#include <SmartLedLight.h>
#include <DistanceTimer.h>
#include <Signal4Aspect.h>

const int triggerPin = 4;
const int stripControllerPin = 5;

DistanceTimer distanceTimer(triggerPin);

SmartLedLight greenLight(CRGB::Green);
SmartLedLight redLight(CRGB::Red);
SmartLedLight yellowLight1(CRGB::Orange);
SmartLedLight yellowLight2(CRGB::Orange);
SmartLed upperLed(0, yellowLight2);
SmartLed lowerLed(1, redLight, yellowLight1, greenLight);
NeoPixelStrip<stripControllerPin> ledStrip(upperLed, lowerLed);
//SK6812Strip<stripControllerPin> ledStrip2(2);  // Not used. Provided as example of using default colour order.
//SK6812Strip<stripControllerPin, RGB> ledStrip3(2);  // Not used. Provided as example of specifying colour order.

Signal4Aspect signal1(distanceTimer, greenLight, redLight, yellowLight1, yellowLight2);

void setup() 
{
  ledStrip.setBrightness(40);
  ledStrip.setTemperature(Tungsten100W);
}

void loop() 
{
  distanceTimer.update();
  signal1.update();
  ledStrip.update();
}
