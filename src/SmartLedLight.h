#include <FastLED.h>
#include <Light.h>

class SmartLed;

class SmartLedLight : public Light
{
  bool lightOn;
  CRGB::HTMLColorCode color;

public:
  SmartLedLight(CRGB::HTMLColorCode color)
    : lightOn(false)
    , color(color)
  {
  }

  void set(bool lightOn) override
  {
    this->lightOn = lightOn;
  }

  bool get() const
  {
    return lightOn;
  }

  CRGB::HTMLColorCode getColor() const
  {
    return color;
  }

  void update() override
  {
    // Nothing to do here.
  }
};
