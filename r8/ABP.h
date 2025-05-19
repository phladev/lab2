#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int info;
  struct NO *esq;
  struct NO *dir;
} NO;

typedef struct NO* ABP; 

ABP* criaABP() {
  ABP* raiz = (ABP*)malloc(sizeof(ABP));
  if(raiz != NULL) {
    *raiz = NULL;
  }
  return raiz;
}

void destroiRec(NO* no) {
  if(no != NULL) {
    destroiRec(no->esq);
    destroiRec(no->dir);
    free(no);
    no = NULL;
  }
}

void destroiABP(ABP* raiz) {
  if(raiz != NULL) {
    destroiRec(*raiz);
    free(raiz);
  }
}

int estaVazia(ABP* raiz) {
  return (raiz == NULL || *raiz == NULL);
}

NO* alocaNO() {
  NO* novo = (NO*)malloc(sizeof(NO));
  if(novo != NULL) {
    novo->esq = NULL;
    novo->dir = NULL;
  }
  return novo;
}

int insereRec(NO** raiz, int valor) {
  if(*raiz == NULL) {
    NO* novo = alocaNO();
    if(novo == NULL) return 0;
    novo->info = valor;
    *raiz = novo;
    return 1;
  } else {
    if(valor == (*raiz)->info) {
      return 0;
    } else if(valor < (*raiz)->info) {
      return insereRec(&(*raiz)->esq, valor);
    } else {
      return insereRec(&(*raiz)->dir, valor);
    }
  }
  return 1;
}

int insereValor(ABP* raiz, int valor) {
  if(raiz == NULL) return 0;
  return insereRec(raiz, valor);
}

int pesquisaRec(NO** raiz, int valor) {
  if(*raiz == NULL) return 0;
  if(valor == (*raiz)->info) {
    return 1;
  } else if(valor < (*raiz)->info) {
    return pesquisaRec(&(*raiz)->esq, valor);
  } else {
    return pesquisaRec(&(*raiz)->dir, valor);
  }
}

int pesquisaValor(ABP* raiz, int valor) {
  if(raiz == NULL) return 0;
  if(estaVazia(raiz)) return 0;
  return pesquisaRec(raiz, valor);
}

int removeValor(ABP* raiz, int valor) {
  if(pesquisaValor(raiz, valor) == 0) return 0;
  return removeRec(raiz, valor);
}

int removeRec(NO** raiz, int valor) {
  if(*raiz == NULL) return 0;
  if((*raiz)->info == valor) {
    NO *aux;
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
      free(*raiz);
      *raiz = NULL;
    } else if((*raiz)->esq == NULL) {
      aux = *raiz;
      *raiz = (*raiz)->dir;
      free(aux);
    } else if((*raiz)->dir == NULL) {
      aux = *raiz;
      *raiz = (*raiz)->esq;
      free(aux);
    } else {
      NO *Filho = (*raiz)->esq;
      while(Filho->dir != NULL) {
        Filho = Filho->dir;
      }
      (*raiz)->info = Filho->info;
      Filho->info = valor;
      removeRec(&(*raiz)->esq, Filho->info);
    }
    return 1;
  } else if(valor < (*raiz)->info) {
    return removeRec(&(*raiz)->esq, valor);
  } else {
    return removeRec(&(*raiz)->dir, valor);
  }
}

void em_ordem(NO *raiz, int nivel) {
  if(raiz != NULL) {
    em_ordem(raiz->esq, nivel + 1);
    printf("Nivel %d: %d\n", nivel, raiz->info);
    em_ordem(raiz->dir, nivel + 1);
  }
}

void pre_ordem(NO *raiz, int nivel) {
  if(raiz != NULL) {
    printf("Nivel %d: %d\n", nivel, raiz->info);
    pre_ordem(raiz->esq, nivel + 1);
    pre_ordem(raiz->dir, nivel + 1);
  }
}

void pos_ordem(NO *raiz, int nivel) {
  if(raiz != NULL) {
    pos_ordem(raiz->esq, nivel + 1);
    pos_ordem(raiz->dir, nivel + 1);
    printf("Nivel %d: %d\n", nivel, raiz->info);
  }
}

void imprimeEmOrdem(ABP* raiz) {
  if(raiz == NULL) return;
  if(estaVazia(raiz)) {
    printf("Arvore vazia\n"); 
    return;
  }
  em_ordem(*raiz, 0);
}
void imprimePreOrdem(ABP* raiz) {
  if(raiz == NULL) return;
  if(estaVazia(raiz)) {
    printf("Arvore vazia\n"); 
    return;
  }
  pre_ordem(*raiz, 0);
}
void imprimePosOrdem(ABP* raiz) {
  if(raiz == NULL) return;
  if(estaVazia(raiz)) {
    printf("Arvore vazia\n"); 
    return;
  }
  pos_ordem(*raiz, 0);
}

int numeroNosRec(NO* raiz) {
  if(raiz == NULL) return 0;
  return 1 + numeroNosRec(raiz->esq) + numeroNosRec(raiz->dir);
}

int numeroNos(ABP* raiz) {
  if(raiz == NULL) return 0;
  if(estaVazia(raiz)) return 0;
  return numeroNosRec(*raiz);
}

#endif