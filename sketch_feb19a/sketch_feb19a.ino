#include "LiquidCrystal_I2C.h"
#include "Wire.h"

LiquidCrystal_I2C display(0x27, 16, 2);

void setup() {
  display.init();
  display.backlight();
}

void loop() {
  delay(1000);
  display.setCursor(0, 0);
  display.print("Test");
}
