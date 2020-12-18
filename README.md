# ExtTestC

## Test Releases

Install Extension
 
* https://github.com/ferenc-hechler/pxt-exttestc

and use javasript sources from INFO/test-full.ts in following editors

* CALLIOPE - https://makecode.calliope.cc/#editor
* MICROBIT - https://makecode.microbit.org/#editor
* CALLIOPE/beta - https://makecode.calliope.cc/beta#editor
* MICROBIT/beta - https://makecode.microbit.org/beta#editor

program tested

* HW - HelloWorld
* FULL - test-full.ts

### v0.2.4
 
+ CALLIOPE
+ MICROBIT

### v0.2.5
 
+ CALLIOPE

### v0.2.6

### v0.2.7

added platform/Utils.cpp

+ CALLIOPE
- MICROBIT HW 

### v0.2.8

integrated Utils.h/Utils.cpp into exttestc.cpp

- MICROBIT HW

### v0.2.9

strip down Utils to log()

+ MICROBIT FULL

### v0.3.0

add includes from Utils.cpp




## ~ hint

To use this package, go to https://makecode.microbit.org, click ``Add package`` and search for **gator-light**. The package is located [here](https://makecode.microbit.org/pkg/sparkfun/pxt-gator-light)

## ~

## Basic usage

```blocks
//Sets the value of the light variable to the value read from the gator:light
let light = 0
light = gatorlight.light(AnalogPin.P0, gatorlightType.Lux)
```

Use ``||Get light on pin||`` to read the light value from a gator:light sensor attached to a given pin in lux or the straight ADC value.

## Example: Light Detector

```blocks
//Read light value and write it to the micro:bit screen as a bar graph.
let light = 0
basic.forever(function () {
    light = gatorlight.light(AnalogPin.P0, gatorlightType.Lux)
    led.plotBarGraph(
        light,
        1023
    )
})
```

## Supported targets

* for PXT/microbit

## License

MIT

```package
gatorlight=github:sparkfun/pxt-gator-light