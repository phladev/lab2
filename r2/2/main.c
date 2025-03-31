#include <stdio.h>
#include <string.h>
#include "CatalogoProdutos.h"

int main() {
  CatalogoProdutos catalogo;
  criarCatalogo(&catalogo);
  char nome[50];
  double preco;
  int quantidade;

  for(int i = 0; i < 3; i++) {
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';
    scanf("%lf", &preco);
    scanf("%d", &quantidade);
    getchar();
    adicionarProduto(&catalogo, nome, preco, quantidade);
  }
  printf("Catalogo\n");
  imprimirCatalogo(&catalogo);
  char nomeProduto[50];
  scanf("%s", nomeProduto);
  int quantidadeEstoque = verificarEstoque(&catalogo, nomeProduto);
  printf("Quantidade produto %s: %d\n", nomeProduto, quantidadeEstoque);

  return 0;
}