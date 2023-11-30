#include <Servo.h>

Servo servo1;
Servo servo2;
int pos = 0;
int ledArray[] = {4, 6, 5, 3, 7, 8}; //Creating 6 ledpins and giving them a number corresponding to the digital pins on the arduino
int redTlight = 12;
int yelTlight = 13;
int greTlight = 11;
int sStart = 0;
int sensor = 2;
int detect;

void setup() {
   pinMode(redTlight, OUTPUT);
   pinMode(yelTlight, OUTPUT);
   pinMode(greTlight, OUTPUT);
   digitalWrite(greTlight, HIGH);
   pinMode(sensor, INPUT);
   servo1.attach(9);
   servo2.attach(10); //Initialising both servos
   for (int i = 0; i < 6; i++) {
    pinMode(ledArray[i], OUTPUT); //Initialising each led as an output using a for loop
   }
}

void loop() { 
  detect = digitalRead(sensor);
   if (detect == LOW) { //When the magnet is detected the traffic lights will change form green to amber and then to red
    digitalWrite(greTlight, LOW);
    digitalWrite(yelTlight, HIGH);
    delay(1000);
    digitalWrite(yelTlight, LOW);
    digitalWrite(redTlight, HIGH);
   }
  if (detect == LOW) {
    while(sStart <= 5) { //This while loop operates off of an integer that increases by 1 each time it loops
      for (int i = 0; i < 2; i++) { //Whilst the loop hasnt looped at least 6 times, the leds will keep flashing 
       digitalWrite(ledArray[i], HIGH);
      }
      delay(1000);
      for (int i = 0; i < 2; i++) {
       digitalWrite(ledArray[i], LOW);
      }
      for (int i = 2; i < 6; i++) { //These for loops are efficient ways to turn the leds on and off to create the image of flashing lights
       digitalWrite(ledArray[i], HIGH);
      }
      delay(1000);
      for (int i = 2; i < 6; i++) {
       digitalWrite(ledArray[i], LOW);
      }
      if (sStart == 3) { //When the while loop has looped 3 times the servos will rotate to close the barriers
        servo1.write(180);
        servo2.write(180);
        delay(20);
      }
      if (sStart == 5) { //When the while loop has looped 5 times the servos will rotate to open the barriers back up
        servo1.write(90); 
        servo2.write(90);
        delay(20);
        digitalWrite(redTlight, LOW); //When the train has passed and the barriers are open the traffic lights will go back to being green
        digitalWrite(yelTlight, HIGH);
        delay(1000);
        digitalWrite(yelTlight, LOW);
        digitalWrite(greTlight, HIGH);
      }
      sStart += 1;
    }  
  }
}