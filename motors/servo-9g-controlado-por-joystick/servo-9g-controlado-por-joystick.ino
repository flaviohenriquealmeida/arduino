#include <Servo.h>

#define TEMPO_DE_ESPERA_DO_GIRO 200
#define JOYSTICK_EIXO_X A0
#define JOYSTICK_EIXO_Y A1


Servo servo1;
Servo servo2; 

void setup() {
  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(8);
}

void loop() {
  int x = lerEixoX();
  int y = lerEixoY();
  Serial.println(x);
  Serial.println(y);
  servo1.write(x);
  servo2.write(y);
  esperaGirar();
}

int lerEixoX() {
   return map(analogRead(JOYSTICK_EIXO_X), 0, 1023, 1, 180);
}

int lerEixoY() {
   return map(analogRead(JOYSTICK_EIXO_Y), 0, 1023, 1, 180);
}

void centralizar(Servo servo) {
  servo.write(90);
  esperaGirar();
}

void esperaGirar() {
  delay(TEMPO_DE_ESPERA_DO_GIRO);
}
