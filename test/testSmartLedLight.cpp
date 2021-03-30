#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"
#include "SmartLed.h"
#include "SmartLedLight.h"
#include "SmartLedStripBase.h"

class MockSmartLedStrip : public SmartLedStripBase
{
public:
  MockSmartLedStrip(int nLeds)
    : SmartLedStripBase(nLeds)
  {}
};

void testSmartLedLight_construct()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);
  SmartLedLight light(CRGB::Green, led);

  assertEquals(false, light.get());
  assertEquals(CRGB::Green, light.getColor());
  assertEquals(0, FastLEDtraces.size());
}

void testSmartLedLight_turnOn()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);
  SmartLedLight light(CRGB::Green, led);

  light.set(true);

  assertEquals(true, light.get());
  assertEquals(CRGB::Green, light.getColor());
  assertEquals(0, FastLEDtraces.size());
}

void testSmartLedLight()
{
  testSmartLedLight_construct();
  testSmartLedLight_turnOn();
}
