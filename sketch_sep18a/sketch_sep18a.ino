#include <Servo.h>

int sensorPin = A0;
int ledPin = 9;
Servo myservo

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(13);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  if (sensorValue > 500) {
    digitalWrite(ledPin, HIGH);
    myservo.write(90);
      delay(15);
    }
  else {
    digitalWrite(ledPin, LOW);
    myservo.write(0);
      delay(15);
    }
  }
