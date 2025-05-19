#include <stdio.h>
#include "ABP.h"

int main() {
  ABP* raiz;
  int opcao;

  do{
    printf("Escolha uma opcao:\n");
    printf("1 - Criar ABP\n");
    printf("2 - Inserir um elemento\n");
    printf("3 - Buscar um elemento\n");
    printf("4 - Remover um elemento\n");
    printf("5 - Imprimir a ABP em ordem\n");
    printf("6 - Imprimir a ABP em pre-ordem\n");
    printf("7 - Imprimir a ABP em pos-ordem\n");
    printf("8 - Mostrar a quantidade de nos na ABP\n");
    printf("9 - Destruir a ABP\n");
    printf("10 - Sair\n");
    scanf("%d", &opcao);

    
  } while(opcao != 10);
}