// Define all Pins
#define speedRight 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define speedLeft 10

char bt;

void setup() {
  // Set all defined pins as OUTPUT
  for (int pin = 5; pin <= 10; pin++) {
    pinMode(pin, OUTPUT);
  }
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Check if there is data available to read from serial port
  if (Serial.available() > 0) {
    // Read the incoming byte from serial port
    bt = Serial.read();

    // Perform action based on the received character
    switch (bt) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'R': right(); break;
      case 'L': left(); break;
      case 'S': stop(); break;
    }
  }
}

// Function to move the car forward
void forward() {
  // Set speed and direction of both motors to move forward
  analogWrite(speedRight, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(speedLeft, 150);
}

// Function to move the car backward
void backward() {
  // Set speed and direction of both motors to move backward
  analogWrite(speedRight, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(speedLeft, 150);
}

// Function to turn the car left
void left() {
  // Set speed and direction of both motors to turn left
  analogWrite(speedRight, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(speedLeft, 150);
}

// Function to turn the car right
void right() {
  // Set speed and direction of both motors to turn right
  analogWrite(speedRight, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(speedLeft, 150);
}

// Function to stop the car
void stop() {
  // Stop both motors
  analogWrite(speedRight, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(speedLeft, 0);
}
