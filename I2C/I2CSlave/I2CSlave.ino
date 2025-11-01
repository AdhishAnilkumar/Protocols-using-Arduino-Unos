#include <Wire.h>
#include <Servo.h>

Servo mine;
int ServoPin = 9;
String msg = "";
String reply = "";   
void setup() {
  Serial.begin(9600);
  mine.attach(ServoPin);
  mine.write(0);
 

  Wire.begin(8);   // Slave address = 8
  Wire.onReceive(receiveEvent);   // when master sends data
  Wire.onRequest(requestEvent);   // when master requests reply

  
}

void loop() {
  delay(100); // idle — all work happens in interrupts
}

// === When Master sends data ===
void receiveEvent(int howMany) {
  
  
  msg = "";
  
  while (Wire.available()) {
    char c = Wire.read();
    msg += c;
  }

  msg.trim();

  Serial.println(msg);

  // Control servo
  if (msg == "RIGHT"||msg =="right") {
    mine.write(0);
    reply = "Servo RIGHT";
  } 
  else if (msg == "LEFT"||msg=="left") {
    mine.write(180);
    reply = "Servo LEFT";
  } 
  else if (msg=="CENTER"||msg=="center"){
    mine.write(90);
    reply = "Servo CENTER";
  }
      else{
             reply="Invalid position";
           }

  Serial.println(reply);
}

// === When Master requests confirmation ===
void requestEvent() {
  Wire.write(reply.c_str());   // send confirmation string back
}