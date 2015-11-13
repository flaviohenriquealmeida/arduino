#include <Servo.h>

#define TEMPO_DE_ESPERA_MUDANCA_POSICAO 2

Servo servo; 

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {

  int posicao = map(analogRead(0), 0, 1023, 0, 180);
  Serial.println(posicao);
  servo.write(posicao);
  delay(TEMPO_DE_ESPERA_MUDANCA_POSICAO);
  
}
void esperaMudarDePosicao() {
  delay(TEMPO_DE_ESPERA_MUDANCA_POSICAO);
}

