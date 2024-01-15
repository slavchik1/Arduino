const int p = 3;
const byte n = 45;
const int t[n] = {1000, 2000, 3000}/*{350, 350, 350, 250, 100, 350, 250, 100, 700, 350, 350, 350, 250, 100, 350, 250, 100, 700, 350, 250, 100, 350, 250, 100, 100, 100, 450, 150, 350, 250, 100, 100, 100, 450, 150, 350, 250, 100, 750}*/;
const int c[n] = {1000, 2000, 3000}/*{392, 392, 392, 311, 466, 392, 311, 466, 392, 587, 587, 587, 622, 466, 369, 311, 466, 392, 784, 392, 392, 784, 739, 698, 659, 622, 659, 415, 554, 523, 493, 466, 440, 466, 311, 369, 311, 466, 392}*/;
const int delay_const = 200;
int delay_var = delay_const;


void setup() {
  pinMode(p, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}


void music() {
  for (int i = 0; i <= n; i++) {
  	tone (p, c[i], t[i] * 2);
    delay (t[i] * 2);
    noTone (p);
  }
}

void light() {
  digitalWrite(5, HIGH);
  delay(delay_var);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(delay_var);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(delay_var);
  digitalWrite(7, LOW);
  if (delay_var >= 100) {
    delay_var *= 0.9;
  } else {
    delay_var = delay_const;
  }
}

void loop {
  music();
  light();
}