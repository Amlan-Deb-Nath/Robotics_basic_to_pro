#include<Servo.h>

Servo servo_1, servo_2, servo_3, servo_4 ;  //servo_1 = left_Right || pos_1
                                            //servo_2 = forward_backward || pos_2
int vry_1 = A0;                             //servo_3 = Up_Down || pos_3                   
int vrx_1 = A1;                             //servo_4 = claw ||pos_4
int vry_2 = A2;
int vrx_2 = A3;

int pos_1 = 4 , pos_2 = 5 , pos_3 = 6 , pos_4 = 7 ;

void setup(){
  Serial.begin(9600);

  servo_1.attach(pos_1);
  servo_2.attach(pos_2);
  servo_3.attach(pos_3);
  servo_4.attach(pos_4);

  /*servo_1.write(90);
  servo_2.write(90);
  servo_3.write(90);
  servo_4.write(90);  */
  
}

void loop(){
  angle_move(servo_1, vry_1 , 0 , 180 );  // Left_Right
  angle_move(servo_2, vrx_1 , 0 , 70 );   // Forward_Backward
  angle_move(servo_3, vrx_2 , 0 , 60  );  // Up_Down
  angle_move(servo_4, vry_2 , 0 , 30  );  // Claw
}

void angle_move(Servo &servo, int module , int angle_min , int angle_max) {
  int sensor_value = analogRead(module);
  int angle = map(sensor_value, 0, 1023, angle_min , angle_max );
  servo.write(angle);
  
  Serial.print("Angle: ");
  Serial.print(angle);
  Serial.print("   Sensor: ");
  Serial.println(module);
  delay(300);
}