#include <stdio.h>
#include "FSE.h"

int main() {
  Fila* fi = criaFila();
  int* valor;

  printf("Fila está vazia? %s\n", estaVazia(fi) ? "Sim" : "Não");

  for (int i = 0; i < 10; i++) {
    enfileirar(fi, i);
  }

  printf("Tamanho da fila: %d\n", tamanhoFila(fi));
  imprime(fi);
  verInicio(fi, valor);
  printf("O inicio da fila é: %d\n", *valor);
  desenfileirar(fi);
  imprime(fi);

  printf("Fila está cheia? %s\n", estaCheia(fi) ? "Sim" : "Não");
  destroiFila(fi);
  return 0;
}