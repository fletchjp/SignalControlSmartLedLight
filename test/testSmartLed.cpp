#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"
#include "SmartLed.h"
#include "SmartLedLight.h"
#include "SmartLedStrip.h"

class MockController;
class MockSmartLedStrip : public SmartLedStrip<MockController, 5>
{
protected:
  using SmartLedStrip<MockController, 5>::leds;
public:
  using SmartLedStrip<MockController, 5>::SmartLedStrip;

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

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(5, lightGreen, lightRed);

  assertEquals(0, FastLEDtraces.size());
}

void testSmartLed_update_lightsOff()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(5, lightGreen, lightRed);
  MockSmartLedStrip strip(led);

  led.update(strip);

  assertEquals((uint32_t)CRGB::Black, strip.getLed(5).getColorCode());
  assertEquals(1, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
}

void testSmartLed_update_lightsGreen()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(5, lightGreen, lightRed);
  MockSmartLedStrip strip(led);

  lightGreen.set(true);
  led.update(strip);

  assertEquals((uint32_t)CRGB::Green, strip.getLed(5).getColorCode());
  assertEquals(1, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
}

void testSmartLed_update_lightsRed()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(5, lightGreen, lightRed);
  MockSmartLedStrip strip(led);

  lightRed.set(true);
  led.update(strip);

  assertEquals((uint32_t)CRGB::Red, strip.getLed(5).getColorCode());
  assertEquals(1, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
}

void testSmartLed_update_lightsBoth()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(5, lightGreen, lightRed);
  MockSmartLedStrip strip(led);

  lightGreen.set(true);
  lightRed.set(true);
  led.update(strip);

  assertEquals((uint32_t)CRGB::Green, strip.getLed(5).getColorCode());
  assertEquals(1, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
}

void testSmartLed()
{
  testSmartLed_construct();
  testSmartLed_update_lightsOff();
  testSmartLed_update_lightsGreen();
  testSmartLed_update_lightsRed();
  testSmartLed_update_lightsBoth();
}
