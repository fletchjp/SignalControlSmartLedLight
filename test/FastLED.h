// This is test shim that replaces the FastLED library with a mock for testing.

#pragma once

#include <stdint.h>
#include <string>
#include <vector>

typedef enum {
    Tungsten100W=0xFFD6AA /* 2850 K, 255, 214, 170 */,
} ColorTemperature;

struct CRGB
{
  typedef enum {
    Green=0x008000,
    Orange=0xFFA500,
    Red=0xFF0000,
    Yellow=0xFFFF00,
    Black=0x000000,
  } HTMLColorCode;

  HTMLColorCode colorcode;

  CRGB()
    : colorcode(HTMLColorCode::Black)
  {}
  CRGB(ColorTemperature temp) {}
  CRGB(HTMLColorCode colorcode)
    : colorcode(colorcode)
  {}
  //  CRGB& operator=(const CRGB& rhs);
  CRGB& operator=(const HTMLColorCode colorcode)
  {
    this->colorcode = colorcode;
    return *this;
  }

  HTMLColorCode getColorCode() const
  {
    return colorcode;
  }
};

class CFastLED
{
  CRGB * trackedLeds;
  int nTrackedLeds;
public:
  template<class Chipset, int pin>
  void addLeds(struct CRGB *data, int nLedsOrOffset);
  void setBrightness(uint8_t scale) {}
  void setTemperature(const struct CRGB & temp) {}
  void show();
};

class NEOPIXEL;
class SK6812;

extern CFastLED FastLED;
extern std::vector<std::string> FastLEDtraces;

template<class Chipset, int pin>
void CFastLED::addLeds(struct CRGB *data, int nLedsOrOffset)
{
  trackedLeds = data;
  nTrackedLeds = nLedsOrOffset;
  FastLEDtraces.push_back(std::string("CFastLED::addLeds<>({leds}, ")
                          + std::to_string(nLedsOrOffset) + ")"); 
}

enum EOrder {
  RGB=0012,
  RBG=0021,
  GRB=0102,
  GBR=0120,
  BRG=0201,
  BGR=0210
};
