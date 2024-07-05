#define IRpin_1 6    // IR pin Right
#define IRpin_2 7    // IR pin Left

const int En_A = 3;  // Enable pin A & B
const int En_B = 10;

const int In1 = 4;   // Input pins of motor driver
const int In2 = 5;
const int In3 = 8;
const int In4 = 9;

const int motorSpeed = 120;  // Motor speed
const int SlowmotorSpeed = 90;

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
    forward();
    Serial.print("  FORWARD"); 
    direction(IRread_right , IRread_left );
  } else if(IRread_right == HIGH && IRread_left == LOW) {
    right();
    Serial.print("  RIGHT");
    direction(IRread_right , IRread_left );  
  } else if(IRread_right == LOW && IRread_left == HIGH) {
    left();
    Serial.print("  LEFT");
    direction(IRread_right , IRread_left );  
  } else {
    stop();
    delay(500);
    backward();
    Serial.print("  BACKWARD");
    direction(IRread_right , IRread_left );  
  }
  delay(50);
}

void forward() {
  analogWrite(En_A, motorSpeed);
  analogWrite(En_B, motorSpeed);
  set_motor(In1, In2, In3, In4, HIGH, LOW, LOW, HIGH);
}

void backward() {
  analogWrite(En_A, SlowmotorSpeed);
  analogWrite(En_B, SlowmotorSpeed);
  set_motor(In1, In2, In3, In4, LOW, HIGH, HIGH, LOW);

  // Keep checking until either sensor detects the line
  while (true) {
    int IRread_right = digitalRead(IRpin_1);
    int IRread_left  = digitalRead(IRpin_2);
    if (IRread_right == LOW || IRread_left == LOW) {
    break; // Exit backward motion when either sensor detects the line
    }
  }
}

void left() {
  analogWrite(En_A, motorSpeed);
  analogWrite(En_B, motorSpeed);
  set_motor(In1, In2, In3, In4, LOW, LOW, LOW, HIGH);
}

void right() {
  analogWrite(En_A, motorSpeed);
  analogWrite(En_B, motorSpeed);
  set_motor(In1, In2, In3, In4, HIGH, LOW, LOW, LOW);
}

void stop() {
  analogWrite(En_A, 0); // Stop motors by setting speed to 0
  analogWrite(En_B, 0);
  set_motor(In1, In2, In3, In4, LOW, LOW, LOW, LOW);
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
