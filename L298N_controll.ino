int En_A = 3;
int En_B = 10;
int In1 = 4;
int In2 = 5;
int In3 = 8;
int In4 = 9;
int speed= 80;

void setup() {
  Serial.begin(9600);
  //pinMode(En_A, OUTPUT);
  //pinMode(En_B, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop() {
  int speed = 140;
  //analogWrite(En_A, speed);
  //analogWrite(En_B, speed);

  forward();
  delay(1000);
  stop();
  delay(1000);
  backward();
  delay(1000);
  left();
  delay(1800);
  right();
  delay(1800);
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
