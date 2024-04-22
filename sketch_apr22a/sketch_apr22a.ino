#include <Otto9.h>
Otto9 Otto;

#define PIN_YL 12 // left leg
#define PIN_YR 9 // right leg
#define PIN_RL 10 // left foot
#define PIN_RR 11 // right foot
#define PIN_Trigger 4  //TRIGGER pin (2)
#define PIN_Echo 6  //ECHO pin (3)
#define PIN_Buzzer 13 //BUZZER pin (13)
#define PIN_ASSEMBLY 7 //ASSEMBLY pin (7) LOW = assembly    HIGH  = normal operation

int distance;
bool obstacleDetected = false;
int T=1000;
int moveId=0;
int moveSize=15;


void setup() {
  Serial.begin(19200);
  Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo);
  pinMode(PIN_ASSEMBLY,INPUT_PULLUP);
  Otto.sing(S_connection);
  Otto.home();
  delay(500);
  while (digitalRead(PIN_ASSEMBLY) == LOW) {
    Otto.home();
    Otto.sing(S_happy_short);
    delay(5000);
  }
}


void loop() {
 if (obstacleDetected) {
        Otto.sing(S_surprise);
        Otto.jump(5, 500);
        Otto.sing(S_cuddly);
        for (int i = 0; i < 3; i++) Otto.walk(1, 1300, -1);
        delay(50);
        for (int i = 0; i < 3; i++) {
            Otto.turn(1, 1000, 1);
            delay(50);
            obstacleDetector(); 
            }  
          }    
          else {
        Otto.walk(1, 1000, 1);
        obstacleDetector();
        }
      
}  


void obstacleDetector() {
  int distance = Otto.getDistance();
  if (distance < 15) obstacleDetected = true;
  else obstacleDetected = false;
  Serial.print(distance);
  Serial.println("cm");
  if(distance < 15){
          obstacleDetected = true;
          Serial.println ("Obstacle Detected! Avoid collision");
        }else{
          obstacleDetected = false;
          Serial.println ("No Obstacle detected! - Keep on walking");
        }
}
