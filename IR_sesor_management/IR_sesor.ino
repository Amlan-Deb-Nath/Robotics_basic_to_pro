#define IRpin  A0  // Digital Pin 2
#define IRpin1 A1  // Digital Pin 3
int i = 0 ;

void setup() { 

Serial.begin(9600);
pinMode(IRpin,INPUT); 
pinMode(IRpin1,INPUT); 
} 
void loop() { 

int IRread =  analogRead(IRpin); 
int IRread1 = analogRead(IRpin1);

Serial.print(" Sensor 1 reading = ");
Serial.print(IRread);
Serial.print("|||  Sensor 2 reading = ");
Serial.println(IRread1);

delay(500);
} 
