// C++ code
//
int output = A0;   // used a 10k resistor
int red = 7,blue = 6, green = 5;

void setup()
{
Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  
}

void loop()
{int result = analogRead(output);
 Serial.println(result);
 if(result>=0 && result <= 779){//2.5 N force
    Red();
 }
 if(result>779 && result <= 856){//5 N force
    Orange();}
 if (result>856 && result <=893){//7.5 N force
    Yellow();
 }
 if (result>893 && result <=914){//10 N force
    Green();
 }
}
void Red(){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
}
void Yellow(){
  digitalWrite(red,HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
}
void Green(){
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
}
void Orange(){
  analogWrite(red,255);
  analogWrite(blue,0);
  analogWrite(green,54);

}