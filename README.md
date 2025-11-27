# Capacitive Touch + IR Remote LED Controller

This project controls an LED using **two real hardware inputs**:

* A **capacitive touch sensor**, and
* An **IR remote**.

## Used Hardware

* Microcontroller 
* Capacitive touch sensor
* IR receiver module 
* IR remote
* LED + resistor



## Features

* Reads real capacitive touch input
* Reads IR remote signals (using IR receiver module)
* Toggles an LED from both inputs
* Debouncing logic
* Clean and simple C++ code



## 📁 Source Code

```
Capacitive_IR_LED_Control.cpp
```

Contains all logic for reading the touch sensor, handling IR input, and controlling the LED.



##  How It Works

###  Capacitive Touch Sensor

When touched, it toggles the LED state.

###  IR Remote

The microcontroller reads the IR code.
If it matches the correct button, the LED toggles.

###  LED Control

The LED turns ON/OFF depending on the last command received.



##  How to Use

1. Connect the touch sensor, IR receiver, and LED to your microcontroller.
2. Update pin numbers in the code.
3. Flash the code to the MCU.
4. Touch the sensor or press the IR remote button to toggle the LED.





