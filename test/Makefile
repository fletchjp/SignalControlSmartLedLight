all: test

test: run-testAll examples
	@: do nothing

run-%: %
	./$<

ARDUINO_LIBRARY=../../libraries
CC=g++
CPPFLAGS=-std=gnu++11 -g -Wall -I../src -I. \
  -I$(ARDUINO_LIBRARY)/SignalControl/src 

testAll : testAll.o \
	TestTools.o \
	ArduinoMock.o \
	testArduino.o \
	FastLED.o \
	SmartLedStripBase.o \
	SmartLed.o \
	testSmartLedStrip.o \
	testSmartLed.o \
	testSmartLedLight.o


SmartLedStripBase.o : ../src/SmartLedStripBase.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@
SmartLed.o : ../src/SmartLed.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

examples: sketchSignal4Aspect.o

depend :
	$(CC) -MM $(CPPFLAGS) *.cpp > dependencies

include dependencies

clean :
	-rm *.o *.exe
