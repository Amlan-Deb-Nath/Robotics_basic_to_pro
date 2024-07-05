int En_A = 3;  // line following
int En_B = 10;
int In1 = 4;
int In2 = 5;
int In3 = 8;
int In4 = 9;
int vrx = A1, vry = A0;

void setup() {
  Serial.begin(9600);
  pinMode(En_A, OUTPUT);
  pinMode(En_B, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop() {
  analogWrite(En_A, 70);
  analogWrite(En_B, 70);

  int forward_backward = analogRead(vrx);
  int left_right = analogRead(vry);
  Serial.print("front and back = ");
  Serial.print(forward_backward);
  Serial.print("  Left and Right = ");
  Serial.println(left_right);

  if (forward_backward >=0 && forward_backward < 500) {
    forward();
  } else if (forward_backward > 530 && forward_backward <=1023) {
    backward();
  } else if (left_right >= 0 && left_right < 495) {
    right();
  } else if (left_right > 520 && left_right <= 1023) {
    left();
  } else{
    stop();
  }
}

void forward() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void backward() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void left() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  delay(500);
  stop();
}

void right() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
  delay(500);
  stop();
}

void stop() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
