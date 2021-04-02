# Feature requests and bugs.

## Warnings for out-of-bounds indexes.
The library allocates a few arrays for keeping data.
Data is operated on via indexes.
Some error notification is required.

A program sketch running on a stand-alone Arduino has no possibilities
of indicating that errors has occurred.
However an Arduino connected to a PC
can show such notifications on the serial monitor.
This is useful during development of the sketch.

The error notifications need to be visible while running on
an Arduino (with serial communication) and while running unit
tests where standard output/error streams can be used.

Implement a notification framework that
* Uses serial communication while running on the Arduino.
* Uses standard error stream while running under unit tests.
* Can be disabled once development phase is over.
  This will save program memory.
  
### Reverse object references
An alternative fix for the array problem is to reverse
the object references and order they are constructed.
E.g. the SmartLedStrip is created last, when the number of
SmartLed objects are known. 
The SmartLedStrip can then be created with the known number of
SmartLed objects and the array can be created with the correct
size. 

Advantages:
* Know how what size each array needs to be.
* Objects are created with a list of their dependent objects.
  This shows clearer what objects belong to each other compared 
  to declaring dependent objects with their owning object as parameter.

Disadvantages:
* Need to call strip.init() in setup(). Prefer to keep code
  in one place, i.e. with constructor.

Possible fixes:
* One fix is to use a static create() method that constructs
  the strip and calls the virtual init method.
* Use a template type on SmartLedStripBase to specify the 
  FastLED type to use with addLeds. 
  SmartLedStripBase now calls FastLED.addLeds().
  * This can be tricky as different types uses different parameters.
