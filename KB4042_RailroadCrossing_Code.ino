#include <Servo.h>

Servo servo1;
Servo servo2;
int pos = 0;
int ledArray[] = {4, 6, 5, 3, 7, 8}; //Creating 6 ledpins and giving them a number corresponding to the digital pins on the arduino
int sStart = 0;
int sensor = 2;
int detect;

void setup() {
   //Serial.begin(9600);
   pinMode(sensor, INPUT);
   servo1.attach(9);
   servo2.attach(10); //Initialising both servos
   for (int i = 0; i < 6; i++) {
    pinMode(ledArray[i], OUTPUT); //Initialising each led as an output using a for loop
   }
}

void loop() {
  detect = digitalRead(sensor); //
  if (detect == LOW) {
    while(sStart <= 5) {
      for (int i = 0; i < 2; i++) {
       digitalWrite(ledArray[i], HIGH);
      }
      delay(1000);
      for (int i = 0; i < 2; i++) {
       digitalWrite(ledArray[i], LOW);
      }
      for (int i = 2; i < 6; i++) {
       digitalWrite(ledArray[i], HIGH);
      }
      delay(1000);
      for (int i = 2; i < 6; i++) {
       digitalWrite(ledArray[i], LOW);
      }
      if (sStart == 3) {
        for(pos = 0; pos <= 90; pos += 1) {
          servo1.write(pos);
          servo2.write(pos);
          delay(20);
        }
      }
      sStart += 1;
      //Serial.println(sStart);
    }  
  }
}