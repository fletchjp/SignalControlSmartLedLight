#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"
#include "SmartLed.h"
#include "SmartLedLight.h"
#include "SmartLedStripBase.h"

class MockSmartLedStrip : public SmartLedStripBase
{
protected:
  using SmartLedStripBase::leds;
public:
  MockSmartLedStrip(int nLeds)
    : SmartLedStripBase(nLeds)
  {}

  CRGB const & getLed(int index)
  {
    return leds[index];
  }
};

void testSmartLed_construct()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);

  assertEquals(0, FastLEDtraces.size());
}

void testSmartLed_addLight()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);
  SmartLedLight light(CRGB::Green, led);

  assertEquals(0, FastLEDtraces.size());
}

void testSmartLed_update_lightsOff()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);
  SmartLedLight lightGreen(CRGB::Green, led);
  SmartLedLight lightRed(CRGB::Red, led);

  led.update();

  assertEquals((uint32_t)CRGB::Black, strip.getLed(5).getColorCode());
  assertEquals(0, FastLEDtraces.size());
}

void testSmartLed_update_lightsGreen()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);
  SmartLedLight lightGreen(CRGB::Green, led);
  SmartLedLight lightRed(CRGB::Red, led);

  lightGreen.set(true);
  led.update();

  assertEquals((uint32_t)CRGB::Green, strip.getLed(5).getColorCode());
  assertEquals(0, FastLEDtraces.size());
}

void testSmartLed_update_lightsRed()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);
  SmartLedLight lightGreen(CRGB::Green, led);
  SmartLedLight lightRed(CRGB::Red, led);

  lightRed.set(true);
  led.update();

  assertEquals((uint32_t)CRGB::Red, strip.getLed(5).getColorCode());
  assertEquals(0, FastLEDtraces.size());
}

void testSmartLed_update_lightsBoth()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  MockSmartLedStrip strip(7);
  SmartLed led(strip, 5);
  SmartLedLight lightGreen(CRGB::Green, led);
  SmartLedLight lightRed(CRGB::Red, led);

  lightGreen.set(true);
  lightRed.set(true);
  led.update();

  assertEquals((uint32_t)CRGB::Green, strip.getLed(5).getColorCode());
  assertEquals(0, FastLEDtraces.size());
}

void testSmartLed()
{
  testSmartLed_construct();
  testSmartLed_addLight();
  testSmartLed_update_lightsOff();
  testSmartLed_update_lightsGreen();
  testSmartLed_update_lightsRed();
  testSmartLed_update_lightsBoth();
}
