#include <NeoPixelStrip.h>
#include <SmartLed.h>
#include <SmartLedLight.h>
#include <DistanceTimer.h>
#include <Signal4Aspect.h>

const int triggerPin = 4;
const int stripControllerPin = 5;

DistanceTimer distanceTimer(triggerPin);

NeoPixelStrip<stripControllerPin> ledStrip(2);
//SK6812Strip<stripControllerPin> ledStrip2(2);  // Not used. Provided as example of using default colour order.
//SK6812Strip<stripControllerPin, RGB> ledStrip3(2);  // Not used. Provided as example of specifying colour order.

SmartLed upperLed(ledStrip, 0);
SmartLed lowerLed(ledStrip, 1);
SmartLedLight greenLight(CRGB::Green, lowerLed);
SmartLedLight redLight(CRGB::Red, lowerLed);
SmartLedLight yellowLight1(CRGB::Orange, lowerLed);
SmartLedLight yellowLight2(CRGB::Orange, upperLed);
Signal4Aspect signal1(distanceTimer, greenLight, redLight, yellowLight1, yellowLight2);

void setup() 
{
  ledStrip.setBrightness(40);
  ledStrip.setTemperature(Tungsten100W);
  signal1.begin();
}

void loop() 
{
  distanceTimer.update();
  signal1.update();
  ledStrip.update();
}
