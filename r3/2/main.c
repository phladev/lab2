#include <stdio.h>
#include "Cubo.h"

int main() {
  float lado;
  printf("Digite o tamanho do lado do cubo: ");
  scanf("%f", &lado);
  Cubo *cubo = criarCubo(lado);

  printf("Lado do cubo: %.2f\n", tamanhoLado(cubo));
  printf("Volume do cubo: %.2f\n", volumeCubo(cubo));
  printf("Área do cubo: %.2f\n", areaCubo(cubo));

  apagarCubo(cubo);
  return 0;
}