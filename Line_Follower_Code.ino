#define LEFT_SENSOR A0 // Left sensor pin
#define RIGHT_SENSOR A1 // Right sensor pin
#define LEFT_MOTOR_PIN1 5 // Left motor pin 1
#define LEFT_MOTOR_PIN2 6 // Left motor pin 2
#define RIGHT_MOTOR_PIN1 9 // Right motor pin 1
#define RIGHT_MOTOR_PIN2 10 // Right motor pin 2

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
}

void loop() {
  int leftSensorValue = analogRead(LEFT_SENSOR);
  int rightSensorValue = analogRead(RIGHT_SENSOR);
  
  // If both sensors are on the line, move forward
  if (leftSensorValue > 500 && rightSensorValue > 500) {
    moveForward();
  } 
  // If left sensor detects the line, turn left
  else if (leftSensorValue > 500) {
    turnLeft();
  } 
  // If right sensor detects the line, turn right
  else if (rightSensorValue > 500) {
    turnRight();
  } 
  // If both sensors are off the line, stop
  else {
    stopCar();
  }
}

void moveForward() {
  digitalWrite(LEFT_MOTOR_PIN1, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

void turnLeft() {
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

void turnRight() {
  digitalWrite(LEFT_MOTOR_PIN1, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

void stopCar() {
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}
