### Pin Test

## Short desc

This app will help you find out which pins are available by only using a male-male wire, when they are not directly connected to the Arduino (such as when using a shield that doesn't number the unused pins).

## Why so complicated?

Because Arduino pins are very sensible, they can read `HIGH` from wires that are not connected, from your skin or even the air. In this case, checking if a pin reads `HIGH` when iterating through them is not an option.

The solution is to use the [pull-up resistors](https://www.arduino.cc/en/Tutorial/DigitalPins) for the digital pins to check when they read a `LOW` value by connecting them one by one to the `GND` of the Arduino.

## Usage 

* Connect one end of the wire to the `GND` of the Arduino

* Set your `ignorePins` array. If using `Serial` to print, ignore pins `0` and `1`

* Connect the other end of the cable to a pin. The screen should display the `pinNumber`




