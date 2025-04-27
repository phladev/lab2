#include <stdio.h>
#include "PSE.h"

int main() {
  Pilha* pi = criaPilha();
  int* valor;

  printf("Pilha está vazia? %s\n", estaVazia(pi) ? "Sim" : "Não");

  for (int i = 0; i < 10; i++) {
    empilhar(pi, i * 5);
  }

  printf("Tamanho da pilha: %d\n", tamanhoPilha(pi));
  imprime(pi);
  verTopo(pi, valor);
  printf("O topo da pilha é: %d\n", *valor);
  desempilhar(pi);
  imprime(pi);

  printf("Pilha está cheia? %s\n", estaCheia(pi) ? "Sim" : "Não");
  destroiPilha(pi);
  return 0;
}