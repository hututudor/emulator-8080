# emulator 8080

> An emulator for the Intel 8080 processor written from scratch in C that has custom hardware emulation for dealing with the Space Invaders arcade machine.

### How to build and run the emulator?
The whole app is built using Cmake and you need to simply run Cmake and build the app yourself.

### What can be done with it?
The emulator is able to both execute any Intel 8080 ROM file, and running the Space Invaders ROM in a more advanced mode, with custom hardware emulation.

The options for the display and stepping through the cpu instructions one at a time are in the emulator.c file, precisely the definition directives.

### How to contribute?
You could also provide more custom hardware emulation for different arcade machine components. For example, the Space Invaders ROM uses a display that is rotated 90 degrees, a hardware bit-shifting mechanism and buttons input. This could be easily expanded in order to support more games or apps.