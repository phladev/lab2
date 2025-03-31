#ifndef CATALOGO_PRODUTOS_H
#define CATALOGO_PRODUTOS_H

#include <stdio.h>
#include <string.h>

typedef struct Produto {
  char nome[50];
  double preco;
  int quantidade;
} Produto;

typedef struct CatalogoProdutos {
  Produto produtos[100];
  int totalProdutos;
} CatalogoProdutos;

void criarCatalogo(CatalogoProdutos *c) {
  c->totalProdutos = 0;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade) {
  strcpy(c->produtos[c->totalProdutos].nome, nome);
  c->produtos[c->totalProdutos].preco = preco;
  c->produtos[c->totalProdutos].quantidade = quantidade;
  c->totalProdutos++;
}

int verificarEstoque(CatalogoProdutos *c, char *nome) {
  for (int i = 0; i < c->totalProdutos; i++) {
    if (strcmp(c->produtos[i].nome, nome) == 0) {
      return c->produtos[i].quantidade;
    }
  }
  return 0;
}

void imprimirCatalogo(CatalogoProdutos *c) {
  for (int i = 0; i < c->totalProdutos; i++) {
    printf("Produto: %s, Preço: %.2lf, Quantidade: %d\n", c->produtos[i].nome, c->produtos[i].preco, c->produtos[i].quantidade);
  }
}

#endif