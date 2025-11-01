#include <LiquidCrystal.h> 
#include <SPI.h>
int rs=7; int en=8; int d4=2; int d5=3; int d6=4; int d7=5; 

LiquidCrystal lcd(7, 8, 2, 3, 4, 5);
float receivedDistance = 0.0;
byte receivedBytes[4];
volatile int byteCount = 0;


 void setup() { 
lcd.begin(16,2); 
pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);               // Enable SPI in slave mode
  SPI.attachInterrupt();
  Serial.begin(9600);
  } 

ISR(SPI_STC_vect) {                       //Interrupt Service Routine 
  receivedBytes[byteCount] = SPDR;
  byteCount++;
  if (byteCount == 4) {
    receivedDistance = *(float*)receivedBytes;  //recieveing bytes 
    byteCount = 0;                              //resetting count 
  }
}

void loop() {
  if (byteCount == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
     lcd.setCursor(0, 1);
    lcd.print(receivedDistance); // Print with 2 decimal places
    delay(500);
  }
}
