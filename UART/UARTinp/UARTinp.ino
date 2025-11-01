String inputString;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    inputString = Serial.readString();  // read whole string
   
    Serial.println(inputString);
  }
}
