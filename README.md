STM32 project to control a light bulb using a Relay Module, a Motion sensor and a Photoresistor (To ensure that the light is not turned on when there is already light present.), interfacing with STM32 using Libopencm3.

In this project, I learned to set up the development environment, the Microcontroller clock, and peripherals such as GPIO and ADC.
Additionally, ARM Cortex-M Systick and interrupts are used to generate accurate delays.

## Hardware
- Relay Module
- Motion sensor
- Photoresistor

## Run
To build the project, navigate to the firmware folder and run
```console

make

```

to compile the project and produce the image.

then run
```console

make burn

```
to burn the image to the Microcontroller flash memory