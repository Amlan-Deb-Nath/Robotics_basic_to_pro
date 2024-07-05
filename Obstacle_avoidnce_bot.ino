#include <Servo.h>   // worlks fully OK

//const int En_A = 3;  // Enable pins for motor driver L298N
//const int En_B = 10;

const int In1 = 4;   // Input pins for motor driver L298N
const int In2 = 5;
const int In3 = 8;
const int In4 = 9;

const int trig = 6, echo = 7; // Ultrasonic sensor pins
const int pos = 11;  // Servo pin

Servo servo_1; // Servo object

//const int motorSpeed = 140; // Motor speed
const int obstacleDistance = 40; // Distance threshold for obstacle detection

float distanceValue, right_distance, left_distance;

float measure_distance(int trig, int echo);

void setup() {
  Serial.begin(9600);
  
  servo_1.attach(pos); // Attach servo to pin
  
  // Set pin modes
 // pinMode(En_A, OUTPUT);
 // pinMode(En_B, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  servo_1.write(90); // Center the servo
}

void loop() {
  distanceValue = measure_distance(trig, echo);
  Serial.println(distanceValue);

 // analogWrite(En_A, motorSpeed);
 // analogWrite(En_B, motorSpeed);

  if (distanceValue > 0 && distanceValue <= obstacleDistance) {
    stop();
    delay(100);
    scan_and_avoid();
  } else if (distanceValue > obstacleDistance) {
    forward();
  }
}

void scan_and_avoid() {
  right_distance = scan_direction(5);
  left_distance = scan_direction(180);
  
  if (left_distance > right_distance) {
    turn_away(left);
  } else {
    turn_away(right);
  }
  servo_1.write(90);
}

float scan_direction(int angle) {
  servo_1.write(angle);
  delay(700);      // Allow time for the servo to move and sensor to stabilize
  return measure_distance(trig, echo);
}

void turn_away(void (*turn_func)()) {  // applying a function inside other function
  backward();
  delay(500);
  stop();
  delay(500);
  turn_func();
  delay(500);
}

void forward() {
  set_motor(In1, In2, In3, In4, HIGH, LOW, LOW, HIGH);
}

void backward() {
  set_motor(In1, In2, In3, In4, LOW, HIGH, HIGH, LOW);
}

void left() {
  set_motor(In1, In2, In3, In4, LOW, LOW, LOW, HIGH);
}

void right() {
  set_motor(In1, In2, In3, In4, HIGH, LOW, LOW, LOW);
}

void stop() {
  set_motor(In1, In2, In3, In4, LOW, LOW, LOW, LOW);
}

void set_motor(int pin1, int pin2, int pin3, int pin4, int val1, int val2, int val3, int val4) {
  digitalWrite(pin1, val1);
  digitalWrite(pin2, val2);
  digitalWrite(pin3, val3);
  digitalWrite(pin4, val4);
}

float measure_distance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  long duration = pulseIn(echo, HIGH);
  float distance = 0.0349 * duration / 2; // Speed of sound 34300 cm/s divided by 2
  delay(80);
  return distance ;// Valid range: 2cm to 400cm
}
