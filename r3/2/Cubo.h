#ifndef CUBO_H
#define CUBO_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cubo {
  float lado;
}Cubo;

Cubo* criarCubo(float lado) {
  Cubo *cubo = (Cubo*)malloc(sizeof(Cubo));
  cubo->lado = lado;
  return cubo;
}

float tamanhoLado(Cubo *cubo) {
  return cubo->lado;
}

float volumeCubo(Cubo *cubo) {
  return pow(cubo->lado, 3);
}

float areaCubo(Cubo *cubo) {
  return 6 * (pow(cubo->lado, 2));
}

void apagarCubo(Cubo *cubo) {
  free(cubo);
}

#endif