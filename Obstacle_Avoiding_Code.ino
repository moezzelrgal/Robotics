#define speedL 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define speedR 5
#define trig 4
#define echo 3

long duration, distance;

void setup() {
  // Set all pins as OUTPUT
  for (int i = 4; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }
  // Set echo pin as INPUT
  pinMode(echo, INPUT);
  // Begin serial communication
  Serial.begin(9600);
}

void Ultrasonic() {
  // Clear trigger pin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  // Send 10us pulse to trigger pin
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Measure the duration of the pulse
  duration = pulseIn(echo, HIGH);
  // Calculate distance
  distance = (duration / 2) * 0.0343;
}

void backword() {
  // Set motor direction for backward motion
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  // Set motor speeds
  analogWrite(speedL, 150);
  analogWrite(speedR, 150);
}

void forward() {
  // Set motor direction for forward motion
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Set motor speeds
  analogWrite(speedL, 150);
  analogWrite(speedR, 150);
}

void left() {
  // Set motor direction for left turn
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  // Set motor speeds
  analogWrite(speedL, 0);
  analogWrite(speedR, 150);
}

void right() {
  // Set motor direction for right turn
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  // Set motor speeds
  analogWrite(speedL, 150);
  analogWrite(speedR, 150);
}

void stopp() {
  // Stop both motors
  digitalWrite(speedL, LOW);
  digitalWrite(speedR, LOW);
}

void loop() {
  // Print distance to serial monitor
  Serial.println(distance);
  // Measure distance using ultrasonic sensor
  Ultrasonic();
  // If obstacle detected within 35 cm
  if (distance < 35 && distance != 0) {
    // Stop motors, delay, move backward, delay, then turn right
    stopp();
    delay(250);
    backword();
    delay(500);
    right();
    delay(500);
  } 
  // If no obstacle detected
  else if (distance == 0) {
    // Move forward
    forward();
  } 
  // If obstacle not too close
  else {
    // Move forward
    forward();
  }
}
