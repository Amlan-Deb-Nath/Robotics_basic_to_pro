// C++ code

int green = 13,orange = 12,red = 11;
int trig = 6,echo = 7;

int measure_distance(int trig, int echo);

void setup()
{
  Serial.begin(9600);
  pinMode(green, OUTPUT);
  pinMode(orange, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
}

void loop()
{
  int result = measure_distance(trig,echo); 
  Serial.print("Distance ");
  Serial.println(result);
  
  if(result>=100){
    digitalWrite(green,HIGH);
    digitalWrite(orange,LOW);
    digitalWrite(red,   LOW);  
}
  else if(result>=50 && result <100){
    digitalWrite(orange,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(green,LOW);
  }
  else if(result >= 0 && result < 50){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(orange,LOW);
  }
}
int measure_distance(int trig, int echo)
{
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  
  int time = pulseIn(echo,HIGH);
  int distance = .03494*time/2 ;
  
  return distance;
}