#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Constants
const int lcd_add = 0x27;
const int lcd_column = 16;
const int lcd_row = 2;
const int pos = 3;
const int trig = 6;
const int echo = 5;
const int light = 13;
const int distanceThreshold = 70;

// Objects
Servo servo_1;
LiquidCrystal_I2C lcd(lcd_add, lcd_column, lcd_row);

// Function Declarations
int measure_distance(int trig, int echo);
void move_servo(int angle);
void move_servo_smooth(int startAngle, int endAngle);
void display_message(const char* message);
void clear_lcd();

void setup() {
  Serial.begin(9600);
  servo_1.attach(pos);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(light, OUTPUT);

  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  int distanceValue = measure_distance(trig, echo);
  Serial.print("Distance: ");
  Serial.print(distanceValue);
  Serial.println(" cm");

  if (distanceValue <= distanceThreshold) {
    digitalWrite(light, HIGH);
    display_message("Hello Sir");
    move_servo_smooth(0, 90);
  } else {
    digitalWrite(light, LOW);
    clear_lcd();
    move_servo_smooth(90, 0);
  }

  delay(100); // Small delay to avoid excessive serial output and flicker
}

int measure_distance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

void move_servo(int angle) {
  servo_1.write(angle);
  delay(15);
}

void move_servo_smooth(int startAngle, int endAngle) {
  if (startAngle < endAngle) {
    for (int angle = startAngle; angle <= endAngle; angle++) {
      move_servo(angle);
    }
  } else {
    for (int angle = startAngle; angle >= endAngle; angle--) {
      move_servo(angle);
    }
  }
}

void display_message(const char* message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
}

void clear_lcd() {
  lcd.clear();
}
