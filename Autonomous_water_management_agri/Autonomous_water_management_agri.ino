#include <LiquidCrystal_I2C.h>


const int lcd_add = 0x27;
const int lcd_column = 16;
const int lcd_row = 2;
LiquidCrystal_I2C lcd(lcd_add, lcd_column, lcd_row);


int output = A0;
int red = 7,blue = 5, green = 4;
int motor = 2 ,buzzer = 12 ;

void setup()
{
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
}

void loop()
{int result = analogRead(output);
 Serial.println(result);
 if(result>=0 && result <= 292){   //DRY
   Red();
   digitalWrite(motor , HIGH);
   
   digitalWrite(buzzer , HIGH);
   delay(20);
   digitalWrite(buzzer , LOW);
   delay(20);
   
   
   lcd.init();
   lcd.clear();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("DRY");
   delay(2000);
   lcd.clear();
    
 }
 if(result>292 && result <= 584){    //MEDIUM
   Yellow();
   
   digitalWrite(motor , LOW);
   
   lcd.init();
   lcd.clear();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("MEDIUM");
   delay(2000);
   lcd.clear();
     
 }
 if (result>584 && result <=876){    //WET
   Green();
   
   digitalWrite(motor , LOW);
   
   lcd.init();
   lcd.clear();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("WET");
   delay(2000);
   lcd.clear();
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
