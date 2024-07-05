#define IRpin_1 6    // IR pin Right     // working
#define IRpin_2 7    // IR pin Left

const int En_A = 3;  // Enable pin A & B
const int En_B = 10;

const int In1 = 4;   // Input pins of motor driver
const int In2 = 5;
const int In3 = 8;
const int In4 = 9;

const int motorSpeed = 100;  // Motor speed
const int SlowmotorSpeed = 100;

void setup() {
  Serial.begin(9600);
  pinMode(En_A, OUTPUT);
  pinMode(En_B, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);

  pinMode(IRpin_1, INPUT); 
  pinMode(IRpin_2, INPUT);
}

void loop() {
  int IRread_right = digitalRead(IRpin_1);  // Reading the value of IR sensor
  int IRread_left  = digitalRead(IRpin_2);
 
  if(IRread_right == LOW && IRread_left == LOW) {
    moveRobot("forward", motorSpeed, motorSpeed);
    Serial.print("  FORWARD"); 
  } else if(IRread_right == HIGH && IRread_left == LOW) {
    moveRobot("right", motorSpeed, motorSpeed);
    Serial.print("  RIGHT");
  } else if(IRread_right == LOW && IRread_left == HIGH) {
    moveRobot("left", motorSpeed, motorSpeed);
    Serial.print("  LEFT");
  } else if(IRread_right == HIGH && IRread_left == HIGH ) {
   // moveRobot("stop", 0, 0);
   // delay(500);
    moveRobot("backward", motorSpeed, motorSpeed);
    Serial.print("  BACKWARD");
  }

  direction(IRread_right , IRread_left );
  delay(50);
}

void moveRobot(String direction, int speedA, int speedB) {
  analogWrite(En_A, speedA);
  analogWrite(En_B, speedB);
  if (direction == "forward") {
    set_motor(In1, In2, In3, In4, HIGH, LOW, LOW, HIGH);
  } else if (direction == "backward") {
    set_motor(In1, In2, In3, In4, LOW, HIGH, HIGH, LOW);
  } else if (direction == "left") {
    set_motor(In1, In2, In3, In4, LOW, LOW, LOW, HIGH);
  } else if (direction == "right") {
    set_motor(In1, In2, In3, In4, HIGH, LOW, LOW, LOW);
  } else if (direction == "stop") {
    set_motor(In1, In2, In3, In4, LOW, LOW, LOW, LOW);
  }
}

void set_motor(int pin1, int pin2, int pin3, int pin4, int val1, int val2, int val3, int val4) {
  digitalWrite(pin1, val1);
  digitalWrite(pin2, val2);
  digitalWrite(pin3, val3);
  digitalWrite(pin4, val4);
}

void direction(int IRread_right , int IRread_left){
  Serial.print(" Sensor 1 reading = ");
  Serial.print(IRread_right);
  Serial.print("|||  Sensor 2 reading = ");
  Serial.println(IRread_left);
}
