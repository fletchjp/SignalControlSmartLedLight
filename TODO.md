# Feature requests and bugs.

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