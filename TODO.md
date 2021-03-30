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
  
