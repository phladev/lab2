#include <stdio.h>
#include "LDE.h"

int main(){
  Lista *L;
  L = criaLista();

  insereFim(L, 10);
  insereFim(L, 30);
  insereFim(L, 70);
  insereFim(L, 25);
  insereFim(L, 40);
  insereFim(L, 50);
  insereFim(L, 60);
  insereFim(L, 80);
  insereFim(L, 90);

  printf("Tamanho lista: %d\n", tamanho(L));
  imprimeLista(L);

  printf("Elemento 13 está na lista? %s\n", procura(L, 13) ? "Sim" : "Não");
  printf("Elemento 25 está na lista? %s\n", procura(L, 25) ? "Sim" : "Não");

  insereOrdenado(L, 5);
  insereOrdenado(L, 27);
  imprimeLista(L);

  removePrimeiroElemento(L, 50);
  imprimeLista(L);

  destroiLista(L);
  return 0;
}
