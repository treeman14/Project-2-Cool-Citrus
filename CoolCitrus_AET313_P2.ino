/*
AET 313 Project 2: Monster's University
Team: Cool Citrus
Jenna Barro & Tre Trevino

INTERACTIONS
- 1: police step through and door closes > sulley drops
- 2: sulley knocks down beds
- 3: sulley roars
- 4: door opens & can lights up
- 5: door closes & door lights up
*/

// -------------------------------------------------------------------------

#include <Servo.h>

//declare variables
Servo myservo1;
Servo myservo3;
Servo myservo4;
Servo myservo5;
const int buttonPin1 = 12;  //1: cabin door
const int buttonPin2 = 13;  //2: sulley jump down
const int buttonPin3 = 8;  //3: bed fall
const int buttonPin4 = 6;  //4: monster roar
const int buttonPin5 = 2;  //5: monster door
const int ledPin = 4;
const int piezoPin = 7;
int check1 = 0;
int check2 = 0;
int check3 = 0;
int check4 = 0;

void setup() {
  myservo1.attach(11); //1: door close
  myservo1.write(0);
  myservo3.attach(10); //3: beds fall
  myservo3.write(0);
  myservo4.attach(9); //2: mike and sulley jump down
  myservo4.write(0);
  myservo5.attach(3); //4 & 5: monster door
  myservo5.write(0);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5,INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);

}

void loop() {
  //1: CABIN DOOR CLOSE (servo)
  if (digitalRead(buttonPin1) == HIGH) {
    myservo1.write(80);
    //servo4.write(180);
    check1 = check1 + 1; 
  } else if (digitalRead(buttonPin1) == LOW && check1 >= 1) {
    myservo1.write(80);
    //myservo4.write(180);
  } else {
    myservo1.write(0);
    myservo4.write(0);
  }

  //2: SULLEY & MIKE JUMP DOWN (servo)
  if (digitalRead(buttonPin2) == HIGH) {
    myservo4.write(180);
    check2 = check2 + 1;
  } else if (digitalRead(buttonPin2) == LOW && check2 >= 1) {
    myservo4.write(180);
  } else {
    myservo4.write(0);
  }

  //3: KNOCK DOWN BED (servo)
  if (digitalRead(buttonPin3) == HIGH) {
    myservo3.write(80);
    check3 = check3 + 1; 
  } else if (digitalRead(buttonPin3) == LOW && check3 >= 1) {
    myservo3.write(80);
  } else {
    myservo3.write(0);
  }

  //4: MONSTER ROAR & MONSTER DOOR OPEN & LIGHT UP (piezo)
  if (digitalRead(buttonPin4) == HIGH) {
    tone(piezoPin, 394, 1000); 
    myservo5.write(75);
    check4 = check4 + 1;
  } else if (digitalRead(buttonPin4) == LOW && check4 == 1) {
    noTone(piezoPin);
    myservo5.write(75);
    check4 = check4 + 1;
  } 

  //5: MONSTER DOOR CLOSE & LIGHT UP (servo & led)
  if (digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin4) == LOW && check4 > 1) {
    myservo5.write(0);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}