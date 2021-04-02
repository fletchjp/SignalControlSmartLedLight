#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"
#include "SmartLedLight.h"

void testSmartLedLight_construct()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight light(CRGB::Green);

  assertEquals(false, light.get());
  assertEquals(CRGB::Green, light.getColor());
  assertEquals(0, FastLEDtraces.size());
}

void testSmartLedLight_turnOn()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight light(CRGB::Green);

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
