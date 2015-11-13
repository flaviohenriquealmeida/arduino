#include <Servo.h>

#define TEMPO_DE_ESPERA_MUDANCA_POSICAO 2
Servo servo; 

int posicaoAtual = 90; 
void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  char ch = Serial.read();
  
  switch(ch) {
    case 'o':
      moverParaEsquerda();
      break;
    case 'p':
      moverParaDireita();
      break;
    case 'c':
      centralizar();
      break;
  }
}

void moverParaEsquerda() {
  if(podeAvancar(posicaoAtual-1)) {
    Serial.println("Moveu para esquerda");
    posicaoAtual--;
    servo.write(posicaoAtual);
    esperaMudarDePosicao();
  }
}
void moverParaDireita() {
  if(podeAvancar(posicaoAtual+1)) {
    Serial.println("Moveu para Direita");
    posicaoAtual++;
    servo.write(posicaoAtual);
    esperaMudarDePosicao();
  }
}

void centralizar() {
  posicaoAtual = 90;
  servo.write(posicaoAtual);
  esperaMudarDePosicao();
}

boolean podeAvancar(int posicaoPretendida) {
  boolean avancou = posicaoPretendida >=0 and posicaoPretendida <= 180;
  if(!avancou) {
    Serial.println("Não pode mais avançar");
    Serial.print("Posição atual: ");
    Serial.println(posicaoAtual);
    Serial.print("Posição pretendida: ");
    Serial.println(posicaoPretendida);
  }
  return avancou;
}

void esperaMudarDePosicao() {
  delay(TEMPO_DE_ESPERA_MUDANCA_POSICAO);
}

