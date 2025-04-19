#include "Semaforo.hpp"
#include <Arduino.h>

#define SEGUNDO 1000

Semaforo::Semaforo(int luzVermelha, int luzAmarela, int luzVerde):
  luzVermelha(luzVermelha),
  luzAmarela(luzAmarela),
  luzVerde(luzVerde) {
    pinMode(luzVermelha, OUTPUT);
    pinMode(luzAmarela, OUTPUT);
    pinMode(luzVerde, OUTPUT);
}

void Semaforo::ligar() {
  digitalWrite(luzVermelha, HIGH);
  digitalWrite(luzAmarela, HIGH);
  digitalWrite(luzVerde, HIGH);
}

void Semaforo::desligar() {
  digitalWrite(luzVermelha, LOW);
  digitalWrite(luzAmarela, LOW);
  digitalWrite(luzVerde, LOW);
}

void Semaforo::temporizar(int segundos) {
  delay(SEGUNDO * segundos);
}

void Semaforo::acenderPare() {
  digitalWrite(luzVermelha, HIGH);
  digitalWrite(luzAmarela, LOW);
  digitalWrite(luzVerde, LOW);
}

void Semaforo::acenderAtencao() {
  digitalWrite(luzVermelha, LOW);
  digitalWrite(luzAmarela, HIGH);
  digitalWrite(luzVerde, LOW);
}

void Semaforo::acenderSiga() {
  digitalWrite(luzVermelha, LOW);
  digitalWrite(luzAmarela, LOW);
  digitalWrite(luzVerde, HIGH);
}