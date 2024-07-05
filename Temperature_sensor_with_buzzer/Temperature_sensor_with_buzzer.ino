// C++ code
int Sensor_input= A0;//sensor input
void setup()
{
 Serial.begin(9600);
  pinMode(7,OUTPUT);//added a buzzer
}

void loop()
{
  int result=temperature();
  Serial.println(result);
  if(result<=-10 || result >100){  //condition of the buzzer
  digitalWrite(7,HIGH);
  }
  else digitalWrite(7,LOW);
}

int temperature(){
int t=analogRead(Sensor_input);
  return map(t,20,358,-40,125);// map function 
}