#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"
#include "NeoPixelStrip.h"
#include "SmartLed.h"
#include "SmartLedLight.h"

void testSmartLedStrip_construct()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed upperLed(0, lightGreen);
  SmartLed lowerLed(1, lightRed);
  NeoPixelStrip<5> ledStrip(upperLed, lowerLed);
  ledStrip.init();

  assertEquals(1, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 2)", FastLEDtraces[0]);
}

void testSmartLedStrip_updateRed()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(0, lightGreen, lightRed);
  NeoPixelStrip<5> strip(led);
  strip.init();
  lightRed.set(true);

  strip.update();

  assertEquals(2, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
  assertEquals("CFastLED::show() led[0]=ff0000", FastLEDtraces[1]);
}

void testSmartLedStrip_updateNoneSet()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(0, lightGreen, lightRed);
  NeoPixelStrip<5> strip(led);
  strip.init();

  strip.update();

  assertEquals(2, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
  assertEquals("CFastLED::show() led[0]=0", FastLEDtraces[1]);
}

void testSmartLedStrip_updateGreen()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(0, lightGreen, lightRed);
  NeoPixelStrip<5> strip(led);
  strip.init();
  lightGreen.set(true);

  strip.update();

  assertEquals(2, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
  assertEquals("CFastLED::show() led[0]=8000", FastLEDtraces[1]);
}

void testSmartLedStrip_updateBothSet()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  SmartLedLight lightGreen(CRGB::Green);
  SmartLedLight lightRed(CRGB::Red);
  SmartLed led(0, lightRed, lightGreen);
  NeoPixelStrip<5> strip(led);
  strip.init();
  lightRed.set(true);
  lightGreen.set(true);

  strip.update();

  assertEquals(2, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 1)", FastLEDtraces[0]);
  assertEquals("CFastLED::show() led[0]=ff0000", FastLEDtraces[1]);
}

void testSmartLedStrip()
{
  testSmartLedStrip_construct();
  testSmartLedStrip_updateNoneSet();
  testSmartLedStrip_updateRed();
  testSmartLedStrip_updateGreen();
  testSmartLedStrip_updateBothSet();
}
