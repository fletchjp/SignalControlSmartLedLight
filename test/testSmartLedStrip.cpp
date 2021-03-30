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

  NeoPixelStrip<5> ledStrip(2);

  assertEquals(1, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 2)", FastLEDtraces[0]);
}

void testSmartLedStrip_constructWithLeds()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  NeoPixelStrip<5> strip(2);
  SmartLed led(strip, 5);
  SmartLedLight lightGreen(CRGB::Green, led);
  SmartLedLight lightRed(CRGB::Red, led);

  assertEquals(1, FastLEDtraces.size());
  assertEquals("CFastLED::addLeds<>({leds}, 2)", FastLEDtraces[0]);
}

void testSmartLedStrip_updateRed()
{
  test();
  clearArduinoValues();
  FastLEDtraces.clear();

  NeoPixelStrip<5> strip(1);
  SmartLed led(strip, 0);
  SmartLedLight lightRed(CRGB::Red, led);
  SmartLedLight lightGreen(CRGB::Green, led);
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

  NeoPixelStrip<5> strip(1);
  SmartLed led(strip, 0);
  SmartLedLight lightRed(CRGB::Red, led);
  SmartLedLight lightGreen(CRGB::Green, led);

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

  NeoPixelStrip<5> strip(1);
  SmartLed led(strip, 0);
  SmartLedLight lightRed(CRGB::Red, led);
  SmartLedLight lightGreen(CRGB::Green, led);
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

  NeoPixelStrip<5> strip(1);
  SmartLed led(strip, 0);
  SmartLedLight lightRed(CRGB::Red, led);
  SmartLedLight lightGreen(CRGB::Green, led);
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
  testSmartLedStrip_constructWithLeds();
  testSmartLedStrip_updateNoneSet();
  testSmartLedStrip_updateRed();
  testSmartLedStrip_updateGreen();
  testSmartLedStrip_updateBothSet();
}
