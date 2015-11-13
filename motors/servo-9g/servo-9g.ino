#include <Servo.h>

#define TEMPO_DE_ESPERA_DO_GIRO 2

Servo servo; 

int anguloAtual = 90; 
void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  char ch = Serial.read();
  
  switch(ch) {
    case 'o':
      girarAntiHorario();
      break;
    case 'p':
      girarHorario();
      break;
    case 'c':
      centralizar();
      break;
  }
}

void girarAntiHorario() {
  if(podeGirar(anguloAtual-1)) {
    Serial.println("Girou sentido anti-horário");
    anguloAtual--;
    servo.write(anguloAtual);
    esperaGirar();
  }
}
void girarHorario() {
  if(podeGirar(anguloAtual+1)) {
    Serial.println("Girou sentido horário");
    anguloAtual++;
    servo.write(anguloAtual);
    esperaGirar();
  }
}

void centralizar() {
  anguloAtual = 90;
  servo.write(anguloAtual);
  esperaGirar();
}

boolean podeGirar(int anguloPretendido) {
  boolean avancou = anguloPretendido >=0 and anguloPretendido <= 180;
  if(!avancou) {
    Serial.println("Não pode mais girar. Chegou ao limite");
    Serial.print("Ângulo atual: ");
    Serial.println(anguloAtual);
    Serial.print("Ângulo pretendido: ");
    Serial.println(anguloPretendido);
  }
  return avancou;
}

void esperaGirar() {
  delay(TEMPO_DE_ESPERA_DO_GIRO);
}

