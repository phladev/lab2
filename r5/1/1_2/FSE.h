#ifndef FSE_H
#define FSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int info;
  struct NO * prox;
}NO;

typedef struct {
  int qtd;
  struct NO * ini;
  struct NO * fim;
}Fila;

Fila* criaFila() {
  Fila* fi = (Fila*)malloc(sizeof(Fila));
  if (fi != NULL) {
    fi->ini = NULL;
    fi->fim = NULL;
    fi->qtd = 0;
  }
  return fi;
}

void destroiFila(Fila *fi) {
  if (fi != NULL) {
    NO* aux;
    while (fi->ini != NULL) {
      aux = fi->ini;
      fi->ini = fi->ini->prox;
      free(aux);
    }
    free(fi);
  }
}

int tamanhoFila(Fila *fi) {
  if (fi == NULL)
    return -1;
  return fi->qtd;
}

int estaCheia(Fila *fi) {
  if (fi == NULL)
    return -1;
  return 0;
}

int estaVazia(Fila *fi) {
  if (fi == NULL)
    return -1;
  return (fi->qtd == 0);
}

int enfileirar(Fila* fi, int elem) {
  if (fi == NULL)
    return 0;
  NO* novo = (NO*)malloc(sizeof(NO));
  if (novo == NULL)
    return 0;
  novo->info = elem;
  novo->prox = NULL;
  if (estaVazia(fi)) {
    fi->ini = novo;
  } else {
    fi->fim->prox = novo;
  }
  fi->fim = novo;
  fi->qtd++;
  return 1;
}

int desenfileirar(Fila* fi) {
  if (fi == NULL)
    return 0;
  if (estaVazia(fi))
    return 0;
  NO* aux = fi->ini;
  fi->ini = fi->ini->prox;
  free(aux);
  fi->qtd--;
  if (fi->ini == NULL)
    fi->fim = NULL;
  return 1;
}

int verInicio(Fila* fi, int* p) {
  if (fi == NULL)
    return 0;
  if (estaVazia(fi))
    return 0;
  *p = fi->ini->info;
  return 1;
}

int imprime(Fila* fi) {
  if (fi == NULL)
    return 0;
  if (estaVazia(fi))
    return 0;
  NO* aux = fi->ini;
  printf("Elementos: \n");
  while (aux != NULL) {
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
  return 1;
}

#endif