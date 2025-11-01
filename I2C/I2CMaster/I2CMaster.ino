#include <Wire.h>
#include <LiquidCrystal.h>

int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String msg = "";
String confirmation = "";

void setup() {
  Wire.begin();          // Join I2C bus as Master
  lcd.begin(16, 2);      // Initialize LCD
  Serial.begin(9600);    // Start Serial Monitor
 
 
}

void loop() {
  
  Serial.println("Enter command:");
  while (Serial.available() == 0) {
    
  }

  msg = Serial.readStringUntil('\n');
  Serial.println(msg);
  msg.trim();   


  // Send string to Slave
  Wire.beginTransmission(8); // Slave address = 8
  Wire.write(msg.c_str());
  Wire.endTransmission();

  delay(100);  // short gap

  // Request confirmation from slave
  Wire.requestFrom(8, 20);  // request up to 20 bytes
  confirmation = "";
  while (Wire.available()) {
    char c = Wire.read();
    confirmation += c;
  }

  confirmation.trim();

  // Display confirmation
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg);
  lcd.setCursor(0, 1);
  lcd.print(confirmation);
   


  delay(3000);  
}