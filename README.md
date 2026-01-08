# automation-system-based-on-humidity
Arduino-Based Humidity Monitoring and Automation System


This project is an automation system that uses a water level sensor as a soil moisture sensor to measure the moisture content in plant soil ,and controls a servo motor ,and turn the led on and off LEDs for status indication according to predetermined threshold values.

# Project Objective
To automatically turn the irrigation mechanism (simulated with a servo motor) on and off according to the soil moisture level and to visually inform the user about the moisture status (with LEDs).

# Hardware Requirements
1x Arduino Uno (or a compatible board)

1x Water Level Sensor (Humidity Sensor)

1x Servo Motor (SG90 etc.)

3x LEDs (Red, Green, Blue)

Jumper Cables and Breadboard

# Component => Arduino Pin
Water Level (Humidity) Sensor => A0

Servo Motor => D9

Red LED => D3

Green LED => D5

Blue LED => D6

# Working Principle and Algorithm

1. Water Level (Humidity) Sensor:
The system continuously reads an analog value between 0 and 1023 from pin A0.

2. Servo Motor (Irrigation Mechanism): 
When sensorValue is behind 0 - 50 (Dry): The servo moves to a 90° angle. (e.g., valve opens)
When sensorValue > 50 (Moist/Wet): The servo moves to a 0° angle (e.g., the valve closes).

3. Status LEDs :
LEDs turn on the humidity level range:
0 - 50: All the LEDs are blinking rapidly (Dry, system activated).
50-100: Red LED turns on (Low humidity level).
100 - 150: Green LED turns on (Medium humidity level).
150 and above: Blue LED turns on (High humidity level).
(I used analogWrite to light up the LEDs because I don't have any resistance. This, prevents the LEDs from burning out.
