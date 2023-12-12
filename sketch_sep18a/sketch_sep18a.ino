#include <Servo.h>

int sensorPin = A0; // пін для зчитування аналогового сигналу від датчика газу
int ledPin = 9; // пін для підключення світлодіода
Servo myservo; // змінна для серводвигуна

void setup() {
  pinMode(sensorPin, INPUT); // встановлюємо пін для зчитування датчика газу як вхід
  pinMode(ledPin, OUTPUT); // встановлюємо пін для світлодіода як вихід
  myservo.attach(13); // встановлюємо пін для сервоприводу 
  digitalWrite(ledPin, LOW); // вимикаємо світлодіод
}

void loop() {
  int sensorValue = analogRead(sensorPin); // зчитуємо значення з датчика газу

  if (sensorValue > 500) { // якщо зчитане значення більше 500, то серводвигун повертається на 90 градусів та вмикається світлодіод
    digitalWrite(ledPin, HIGH); // вмикаємо світлодіод
    myservo.write(90);
      delay(15);
    }
  else { // якщо зчитане значення менше 500, то серводвигун повертається на 0 градусів та вимикається світлодіод
    digitalWrite(ledPin, LOW); // вимикаємо світлодіод
    myservo.write(0);
      delay(15);
    }
  }
