#include "Semaforo.hpp"
#include <Arduino.h> 

// Definindo pinos do LDR e parâmetros do sensor
#define PINO_LDR A0
#define LIMIAR_LDR 512 // Valor do LDR para considerar a ausência de luz (ajustável conforme necessário)

// Instâncias do semáforo
Semaforo semaforo1(5, 6, 7), *semaforo2;

void setup() {
  semaforo2 = new Semaforo(2, 3, 4);
  semaforo1.ligar();
  semaforo2->ligar();
  semaforo1.temporizar(5);
  semaforo1.desligar();
  semaforo2->desligar();
  semaforo1.temporizar(3);
  
  // Inicializa o pino do LDR
  pinMode(PINO_LDR, INPUT);
}

void loop() {
  int valorLDR = analogRead(PINO_LDR);

  if (valorLDR < LIMIAR_LDR) { // Se a luz estiver baixa (modo noturno)
    semaforo1.acenderAtencao();
    semaforo2->acenderAtencao();
    delay(2000);
    semaforo1.desligar();
    semaforo2->desligar();
    delay(1000);
  } else { // Modo diurno
    semaforo1.acenderPare();
    semaforo2->acenderPare();
    delay(1000);

    semaforo1.acenderSiga();
    delay(5000);
    semaforo1.acenderAtencao();
    delay(2000);
    semaforo1.acenderPare();
    delay(1000);
    
    semaforo2->acenderSiga();
    delay(5000);
    semaforo2->acenderAtencao();
    delay(2000);
  }
}
