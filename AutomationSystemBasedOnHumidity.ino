#include <Servo.h> // Including the servo library

// Object and Pin Definitions
Servo Servo;  
const int sensorPin = A0;  // Humidity/Water Level sensor
const int servoPin = 9;    // Servo motor
const int redLed = 3;      // Red Led
const int greenLed = 5;    // Green Led
const int blueLed = 6;    // Blue Led

int sensorValue = 0; // Variable to display the value read from the sensor.

void setup() {

  Servo.attach(servoPin); // Connects the servo motor to the specified pin.
  
  // Sets the Led pins as outputs.
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
  // Start serial communication (to view the values ​​on the screen)
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value (a value between 0 and 1023 will be displayed)
  sensorValue = analogRead(sensorPin);
  
  // Print the value to the screen (for checking)
  Serial.print("Humidity Value: ");
  Serial.println(sensorValue);

  if (sensorValue <= 50) { // If the humidity sensor is less than 50:
    // The lights flicker
    analogWrite(redLed, 30);
    analogWrite(greenLed, 30);
    analogWrite(blueLed, 30);
    delay(200);
    analogWrite(redLed, 0);
    analogWrite(greenLed, 0);
    analogWrite(blueLed, 0);
    delay(200);
    Servo.write(90); // Servo rotates 90 degrees.
  } 
  // If the humidity sensor reading is greater than 50, the servo will set to 0 degrees.
  else if (sensorValue > 50) {
    Servo.write(0);
  }

  // Red LED lights up between 50-100, and turns off at other times.
  if (sensorValue >= 50 && sensorValue <= 100) {
    analogWrite(redLed, 30);
  } else {
    analogWrite(redLed, 0);
  }

  // Green LED lights up between 100-150, and turns off at other times.
  if (sensorValue > 100 && sensorValue <= 150) {
    analogWrite(greenLed, 30);
  } else {
    analogWrite(greenLed, 0);
  }

  // Blue LED lights up, when the humidity sensor reading is greater than 150.
  if (sensorValue > 150) {
    analogWrite(blueLed, 30);
  } else {
    analogWrite(blueLed, 0);
  }

  // A short delay between readings (to prevent vibration)
  delay(100);
}