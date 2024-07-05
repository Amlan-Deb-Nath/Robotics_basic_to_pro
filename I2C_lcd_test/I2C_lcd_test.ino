#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Initialize the liquid crystal library
// The first parameter is the I2C address
// The second parameter is the number of columns on your screen
// The third parameter is the number of rows on your screen
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize LCD screen
  lcd.init();
  // Turn on the backlight
  lcd.backlight();
}

void loop() {
  delay(1000);
  char arr[32] = "Hello Boss";  // character String
  lcd.setCursor(0, 0);          // Coordinates Column & Row
  lcd.print(arr);
 
  lcd.setCursor(2, 1);          // Coordinates Column & Row
  lcd.print("How are you?");
}
