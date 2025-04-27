#ifndef PSE_H
#define PSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int info;
  struct NO* prox;
}NO;

typedef struct Pilha {
  int qtd;
  NO* topo;
}Pilha;

Pilha* criaPilha() {
  Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
  if(pi != NULL) {
    pi->qtd = 0;
    pi->topo = NULL;
  }
  return pi;
}

void destroiPilha(Pilha* pi) {
  if(pi != NULL) {
    NO* aux;
    while(pi->topo != NULL) {
      aux = pi->topo;
      pi->topo = pi->topo->prox;
      free(aux);
    }
    free(pi);
  }
}

int tamanhoPilha(Pilha* pi) {
  if(pi == NULL) return -1;
  return pi->qtd;
}

int estaCheia(Pilha* pi) {
  if(pi == NULL) return -1;
  return 0;
}

int estaVazia(Pilha* pi) {
  if(pi == NULL) return -1;
  return (pi->topo == NULL);
}

int empilhar(Pilha* pi, int elem) {
  if(pi == NULL) return 0;
  NO* novo = (NO*) malloc(sizeof(NO));
  if(novo == NULL) return 0;
  novo->info = elem;
  novo->prox = pi->topo;
  pi->topo = novo;
  pi->qtd++;
  return 1;
}

int desempilhar(Pilha* pi) {
  if(pi == NULL) return 0;
  if(estaVazia(pi)) return 0;
  NO* aux = pi->topo;
  pi->topo = pi->topo->prox;
  free(aux);
  pi->qtd--;
  return 1;
}

int verTopo(Pilha* pi, int* p) {
  if(pi == NULL) return 0;
  if(estaVazia(pi)) return 0;
  *p = pi->topo->info;
  return 1;
}

int imprime(Pilha* pi) {
  if(pi == NULL) return 0;
  if(estaVazia(pi)) return 0;
  NO* aux = pi->topo;
  printf("Elementos: \n");
  while(aux != NULL) {
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
  return 1;
}

#endif