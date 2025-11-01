#include <SPI.h>

int trigPin = 2; 
int echoPin = 3; 
float time; 
float distance; 

void setup() { 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(SS, OUTPUT);     
  SPI.begin();
  Serial.begin(9600);      
} 

void loop() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  
  time = pulseIn(echoPin, HIGH);
  distance = time * 0.0343 / 2;  // distance in cm

  // Convert float to 4 bytes
  byte *bytes = (byte*)&distance;  //transfer by bytes 
  digitalWrite(SS, LOW);
  for (int i = 0; i < 4; i++) {    //float datatype takes 4 bytes so transferring 4 bytes 
    SPI.transfer(bytes[i]);
  }
  digitalWrite(SS, HIGH);

  delay(500);
  Serial.println(distance);
}

