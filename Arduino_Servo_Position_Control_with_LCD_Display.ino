#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define potpin A0  // analog pin used to connect the potentiometer

Servo myservo;  // create servo object to control a servo
LiquidCrystal_I2C LCD(0x27, 16, 2);

int val;    // variable to read the value from the analog pin

void setup() {
  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("servo Degree: ");
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(val); 
  LCD.setCursor(7, 1);
  Serial.println(val);
  
  if(val < 100) {
    LCD.print(" ");  // add leading space for numbers less than 100
  }
  LCD.print(val);                 // sets the servo position according to the scaled value
  delay(15);                       // waits for the servo to get there
}
