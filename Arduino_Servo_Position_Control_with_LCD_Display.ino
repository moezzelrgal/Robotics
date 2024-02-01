#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define potpin A0  // Analog pin used to connect the potentiometer

Servo myservo;  // Create servo object to control a servo
LiquidCrystal_I2C LCD(0x27, 16, 2);  // Define LCD object

int val;    // Variable to read the value from the analog pin

void setup() {
  LCD.init();  // Initialize LCD
  LCD.backlight();  // Turn on LCD backlight
  LCD.setCursor(0, 0);  // Set cursor position
  LCD.print("servo Degree: ");  // Print text on LCD
  myservo.attach(9);  // Attach the servo to pin 9
}

void loop() {
  val = analogRead(potpin);  // Read the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);  // Scale it for use with the servo (value between 0 and 180)
  myservo.write(val);  // Set the servo position based on the scaled value
  LCD.setCursor(7, 1);  // Set cursor position
  Serial.println(val);  // Print the current servo position to the Serial Monitor
  
  if (val < 100) {
    LCD.print(" ");  // Add leading space for numbers less than 100
  }
  LCD.print(val);  // Print the current servo position on the LCD
  delay(15);  // Wait for the servo to reach the desired position
}

