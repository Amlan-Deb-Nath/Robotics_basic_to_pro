// C++ code
#include<Servo.h>

Servo servo_1;
int input=A0;
void setup()
{
  Serial.begin(9600);
  servo_1.attach(7);
}

void loop()
{
  int result = angle();
  servo_1.write(result);
  delay(15);
  Serial.println(result);
}
int angle(){
  int sensor_value= analogRead(input);
  int angle= map(sensor_value,682,275,0,180);// Used a 60 K_ohm resistor
 return angle;
}