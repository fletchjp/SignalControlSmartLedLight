#include <map>
#include <string>
#include "testArduino.hpp"
#include "testSmartLedStrip.h"
#include "testSmartLed.h"
#include "testSmartLedLight.h"

std::map<std::string, void (*)()> suites = {
  {"Arduino", testArduino},
  {"SmartLedLight", testSmartLedLight},
  {"SmartLed", testSmartLed},
  {"SmartLedStrip", testSmartLedStrip},
};

int main(int argc, const char * const * argv)
{
  if (*++argv == nullptr)
  {
    for (auto const &i : suites)
    {
      i.second();
    }
  }
  else
  {
    while (const char * arg = *argv++)
    {
      suites[arg]();
    }
  }
}
