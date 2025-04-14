#include <stdio.h>
#include "ListaEstatica.h"

int main() {
  Lista* lista = criaLista();

  for(int i = 0; i < 5; i++) {
    int x;
    scanf("%d", &x);
    insereFim(lista, x);
  }
  
  insereIni(lista, 10);
  insereIni(lista, 20);
  printf("Tamanho da lista: %d\n", tamanhoLista(lista));
  
  printf("Antes da inserção ordenada:\n");
  imprimeLista(lista);

  insereOrdenado(lista, 15);
  insereOrdenado(lista, 2);
  printf("Depois da inserção ordenada:\n");
  imprimeLista(lista);
  
  destroiLista(lista);
  
  return 0;
}