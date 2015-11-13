#include <Servo.h>

#define TEMPO_DE_ESPERA_DO_GIRO 2

Servo servo; 

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {

  // lê do potenciômetro 
  int angulo = map(analogRead(0), 0, 1023, 0, 180);
  Serial.println(angulo);
  servo.write(angulo);
  esperaGirar();
  
}
void esperaGirar() {
  delay(TEMPO_DE_ESPERA_DO_GIRO);
}

