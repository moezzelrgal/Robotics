#include <Servo.h>

Servo myservo; // Define servo object

// Define pin assignments
#define speedRight 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define speedLeft 10
#define IR 3
#define buzzer 4

char bt; // Variable to store received character
bool IrRead; // Variable to store IR sensor reading

void setup() {
  myservo.attach(11); // Attach servo to pin 11
  pinMode(buzzer, OUTPUT); // Set buzzer pin as OUTPUT
  pinMode(IR, INPUT); // Set IR sensor pin as INPUT

  // Set all defined pins as OUTPUT
  for (int pin = 5; pin <= 10; pin++) {
    pinMode(pin, OUTPUT);
  }

  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Check if there is data available to read from serial port
  if (Serial.available() > 0) {
    // Read the incoming byte from the serial port
    bt = Serial.read();

    // Perform action based on the received character
    switch (bt) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'R': right(); break;
      case 'L': left(); break;
      case 'S': stopCar(); break;
    }
  }
  
  // Check IR sensor reading
  IrRead = digitalRead(IR);
  if (IrRead == 0) {
    // If obstacle detected, sound the buzzer
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 392, 1000);
    delay(1000);
    tone(buzzer, 3136, 1000);
    delay(1000);
    digitalWrite(buzzer, LOW);
  }
  
  // Sweep the servo motor
  sweep();
}

// Function to move the car forward
void forward() {
  // Set speed and direction of both motors to move forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(speedRight, 150);
  analogWrite(speedLeft, 150);
}

// Function to move the car backward
void backward() {
  // Set speed and direction of both motors to move backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(speedRight, 150);
  analogWrite(speedLeft, 150);
}

// Function to turn the car left
void left() {
  // Set speed and direction of both motors to turn left
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(speedRight, 150);
  analogWrite(speedLeft, 150);
}

// Function to turn the car right
void right() {
  // Set speed and direction of both motors to turn right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(speedRight, 150);
  analogWrite(speedLeft, 150);
}

// Function to stop the car
void stopCar() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(speedRight, 0);
  analogWrite(speedLeft, 0);
}

// Function to sweep the servo motor
void sweep() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
