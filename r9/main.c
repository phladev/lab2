#include <stdio.h>
#include "AVL.h"


int main() {
  AVL* raiz = NULL;
  int opcao;

  do{
    printf("Escolha uma opcao:\n");
    printf("1 - Criar AVL\n");
    printf("2 - Inserir um elemento\n");
    printf("3 - Buscar um elemento\n");
    printf("4 - Remover um elemento\n");
    printf("5 - Imprimir a AVL em ordem\n");
    printf("6 - Mostrar a quantidade de nos na AVL\n");
    printf("7 - Destruir a AVL\n");
    printf("8 - Sair\n");
    scanf("%d", &opcao);


    switch(opcao) {
      case 1:
        raiz = criarAVL();
        if(raiz != NULL) {
          printf("AVL criada com sucesso!\n");
        } else {
          printf("Erro ao criar AVL.\n");
        }
        break;
      case 2: {
        int valor;
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &valor);
        insereValor(raiz, valor);
        break;
      }
      case 3: {
        int valor;
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &valor);
        if(pesquisa(raiz, valor)) {
          printf("Valor %d encontrado na AVL!\n", valor);
        } else {
          printf("Valor %d nao encontrado na AVL.\n", valor);
        }
        break;
      }
      case 4: {
        int valor;
        printf("Digite o valor a ser removido: ");
        scanf("%d", &valor);
        removeValor(raiz, valor);
        break;
      }
      case 5:
        imprimeAVL(raiz);
        break;
      case 6:
        printf("Quantidade de nos na AVL: %d\n", numeroNos(raiz));
        break;
      case 7:
      destroiAVL(raiz);
      printf("AVL destruida com sucesso!\n");
      break;
      case 8:
      printf("Saindo...\n");
      break;
      default:
        printf("Opcao invalida. Tente novamente.\n");
    }
   
  } while(opcao != 8);

  return 0;
}
