#include <Servo.h>

int vrx = A1, vry = A0;
int pos1 = 6, pos2 = 7;
Servo servo_1;
Servo servo_2;

void setup() {
  Serial.begin(9600);
  servo_1.attach(pos1);
  servo_2.attach(pos2);

  servo_1.write(90);
  servo_2.write(90);
}

void loop() {
  angle_move(servo_1, vrx , 0 , 70 );//fb
  angle_move(servo_2, vry , 0 , 60 );//up_down
  Serial.println(" ");
}

void angle_move(Servo &servo, int module , int angle_min , int angle_max) {
  int sensor_value = analogRead(module);
  int angle = map(sensor_value, 0, 1023, angle_min , angle_max );
  servo.write(angle);
 /* Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print("   Sensor: ");
  Serial.println(module);*/
  Serial.print(sensor_value); Serial.print("  ");
  delay(100);
}
