#include <stdio.h>
#include "LSE.h"

int main(){
  Lista *L;
  L = criaLista();

  insereFim(L, 10);
  insereFim(L, 20);
  insereFim(L, 30);
  insereFim(L, 40);
  insereFim(L, 50);
  insereFim(L, 60);
  insereFim(L, 70);
  insereFim(L, 80);
  insereFim(L, 90);

  printf("Tamanho lista: %d\n", tamanho(L));
  imprimeLista(L);

  printf("Elemento 10 está na lista? %s\n", procura(L, 10) ? "Sim" : "Não");
  printf("Elemento 1 está na lista? %s\n", procura(L, 100) ? "Sim" : "Não");
  destroiLista(L);
  return 0;
}
