#include "FastLED.h"

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> FastLEDtraces;

void CFastLED::show()
{
  std::ostringstream os;
  os << "CFastLED::show()";
  for (int i = 0 ; i < nTrackedLeds ; ++i)
  {
    os << " led[" << i << "]=" << std::hex << trackedLeds[i].getColorCode();
  }
  FastLEDtraces.push_back(os.str());
}

CFastLED FastLED;
