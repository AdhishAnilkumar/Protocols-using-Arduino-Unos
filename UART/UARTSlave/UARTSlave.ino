#include <LiquidCrystal.h>

int rs=7, en=8, d4=9, d5=10, d6=11, d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
String msg;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);   // start UART for Arduino #2
}

void loop() {
  if (Serial.available()) {
    msg = Serial.readStringUntil('\n');
     msg.trim();//trim the last character

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(msg);
  }
}
