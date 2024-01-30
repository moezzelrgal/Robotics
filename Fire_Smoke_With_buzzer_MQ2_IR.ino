// ********************************************************************************
// ********************************************************************************
// ************ Fire and Smoke Detection System with Gas and IR Sensors************
// ********************************************************************************
// ********************************************************************************


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Configuration
LiquidCrystal_I2C LCD(0x27, 16, 2);

// Pin definitions
#define buzzer 4
#define MQ2 A0
#define IR 3

// Sensor readings
int MQ2Read;
bool IrRead;

void setup() {
  Serial.begin(9600);

  // Initialize LCD and sensors
  LCD.init();
  LCD.backlight();
  LCD.setCursor(0, 0);
  LCD.print("Fire: ");
  LCD.setCursor(0, 1);
  LCD.print("Smoke: ");
  
  pinMode(buzzer, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(MQ2, INPUT);
}

void loop() {
  // Read sensor values
  MQ2Read = analogRead(MQ2);
  IrRead = digitalRead(IR);

  // Display sensor readings
  Serial.print("Gas Sensor: ");
  Serial.println(MQ2Read);
  Serial.print("IR Sensor: ");
  Serial.println(IrRead);

  // Perform actions based on sensor readings
  if (MQ2Read < 500 && IrRead == 1) {
    // No Fire, No Smoke
    LCD.setCursor(6, 0);
    LCD.print(" NO ");
    LCD.setCursor(7, 1);
    LCD.print("NO ");
  } else if (MQ2Read >= 500 && IrRead == 1) {
    // Fire detected
    LCD.setCursor(6, 0);
    LCD.print(" NO ");
    LCD.setCursor(7, 1);
    LCD.print("YES ");
    
    // Activate buzzer with two different frequencies
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 392, 1000);
    delay(1000);
    tone(buzzer, 3136, 1000);
    delay(1000);
    digitalWrite(buzzer, LOW);
    
    delay(2000);  // Wait for 2 seconds
  } else if (MQ2Read < 550 && IrRead == 0) {
    // Smoke detected
    LCD.setCursor(6, 0);
    LCD.print(" Yes ");
    LCD.setCursor(7, 1);
    LCD.print(" NO ");
    
    // Activate buzzer with two different frequencies
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 392, 1000);
    delay(1000);
    tone(buzzer, 3136, 1000);
    delay(1000);
    digitalWrite(buzzer, LOW);
    
    delay(2000);  // Wait for 2 seconds
  } else {
    // Fire and Smoke detected
    // Activate buzzer with two different frequencies
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 748, 1000);
    delay(1000);
    tone(buzzer, 3520, 1000);
    delay(1000);
    digitalWrite(buzzer, LOW);
    
    LCD.setCursor(6, 0);
    LCD.print(" Yes ");
    LCD.setCursor(7, 1);
    LCD.print("YES ");
  }
}
