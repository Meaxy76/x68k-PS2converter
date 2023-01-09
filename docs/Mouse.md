# PS/2 Mouse to x68000 mouse

This converter create the possibility of plugging a PS/2 mouse into a Sharp x68000 using an Arduino

## The mouse

For the test, I used a Microsoft Mouse Port Compatible Mouse 2.1A

## Installation

You need to connect the PS/2 connector correctly

```bash
Pin 1 +DATA -> Arduino D7
Pin 2 -> Not Connected
Pin 3 GND -> Arduino GND
Pin 4 VCC -> Arduino 5V
Pin 5 +CLK -> Arduino D2
Pin 6 -> Not Connected
```

## Test in Arduino IDE

The data can be showed in the Serial Monitor from Arduino IDE like this:

```bash
Status   Position X   Position X
   8       PX:0	        PY:0
```