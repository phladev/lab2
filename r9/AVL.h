#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct NO {
  int info;
  int altura;
  int fb;
  struct NO *esq;
  struct NO *dir;
}NO;

typedef struct NO* AVL;

AVL* criarAVL() {
  AVL* raiz = (AVL*)malloc(sizeof(AVL));
  if (raiz != NULL) {
    *raiz = NULL;
  }
  return raiz;
}

void destroiRec(NO* no) {
  if(no == NULL) return;
  destroiRec(no->esq);
  destroiRec(no->dir);
  free(no);
  no = NULL;
}

void destroiAVL(AVL* raiz) {
  if (raiz != NULL) {
    destroiRec(*raiz);
    free(raiz);
  }
}

int estaVazia(AVL* raiz) {
  return (raiz == NULL || *raiz == NULL);
}

int pesquisaRec(AVL* raiz, int chave) {
  if(*raiz == NULL) return 0;
  if((*raiz)->info == chave) return 1;
  if(chave < (*raiz)->info) {
    return pesquisaRec(&(*raiz)->esq, chave);
  } else {
    return pesquisaRec(&(*raiz)->dir, chave);
  }
}

int pesquisa(AVL* raiz, int chave) {
  if (raiz == NULL || estaVazia(raiz)) return 0;
  return pesquisaRec(raiz, chave);
}

void em_ordem(NO* raiz, int nivel) {
  if (raiz == NULL) return;
  em_ordem(raiz->esq, nivel + 1);
  printf("Nivel %d: %d (Altura: %d, FB: %d)\n", nivel, raiz->info, raiz->altura, raiz->fb);
  em_ordem(raiz->dir, nivel + 1);
}

void imprimeAVL(AVL* raiz) {
  if (raiz == NULL || estaVazia(raiz)) {
    printf("A árvore está vazia.\n");
    return; 
  }
  printf("Árvore AVL em ordem:\n");
  em_ordem(*raiz, 0);
}

int altura(NO* raiz) {
  if (raiz == NULL) return 0;
  if(raiz->altura > 0) {
    return raiz->altura;
  } else {
    return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
  }
}

int FB(NO* raiz) {
  if (raiz == NULL) return 0;
  return altura(raiz->esq) - altura(raiz->dir);
}

void rotacaoSimplesDireita(AVL* raiz) {
  NO* aux = (*raiz)->esq;
  (*raiz)->esq = aux->dir;
  aux->dir = *raiz;

  (*raiz)->altura = aux->altura = -1;
  aux->altura = altura(aux);
  (*raiz)->altura = altura(*raiz);
  aux->fb = FB(aux);
  (*raiz)->fb = FB(*raiz);

  *raiz = aux;
}

void rotacaoSimplesEsquerda(AVL* raiz) {
  NO* aux = (*raiz)->dir;
  (*raiz)->dir = aux->esq;
  aux->esq = *raiz;

  (*raiz)->altura = aux->altura = -1;
  aux->altura = altura(aux);
  (*raiz)->altura = altura(*raiz);
  aux->fb = FB(aux);
  (*raiz)->fb = FB(*raiz);

  *raiz = aux;
}

void rotacaoDuplaEsqDir(AVL* raiz) {
  rotacaoSimplesEsquerda(&(*raiz)->esq);
  rotacaoSimplesDireita(raiz);
}

void rotacaoDuplaDirEsq(AVL* raiz) {
  rotacaoSimplesDireita(&(*raiz)->dir);
  rotacaoSimplesEsquerda(raiz);
}

void avl_AuxFE(AVL* raiz) {
  NO *fe = (*raiz)->esq;
  if(fe->fb == 1) {
    rotacaoSimplesDireita(raiz);
  } else if(fe->fb == -1) {
    rotacaoDuplaEsqDir(raiz);
  }
}

void avl_AuxFD(AVL* raiz) {
  NO *fd = (*raiz)->dir;
  if(fd->fb == -1) {
    rotacaoSimplesEsquerda(raiz);
  } else if(fd->fb == 1) {
    rotacaoDuplaDirEsq(raiz);
  }
}

int insereValorRec(AVL* raiz, int valor) {
  int ok;
  if(*raiz == NULL) {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return 0;
    novo->info = valor;
    novo->altura = 1;
    novo->fb = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
    return 1;
  } else {
    if((*raiz)->info == valor) {
      printf("Valor %d já existe na árvore.\n", valor);
      return 0;
    } else if(valor < (*raiz)->info) {
      ok = insereValorRec(&(*raiz)->esq, valor);
      if(ok) {
        switch((*raiz)->fb) {
          case -1:
            (*raiz)->fb = 0;
            ok = 0;
            break;
          case 0: 
            (*raiz)->fb = 1;
            (*raiz)->altura++;
            break;
          case 1:
            avl_AuxFE(raiz);
            ok = 0;
            break;
        }
      }
    } else if(valor > (*raiz)->info) {
      ok = insereValorRec(&(*raiz)->dir, valor);
      if(ok) {
        switch((*raiz)->fb) {
          case 1:
            (*raiz)->fb = 0;
            ok = 0;
            break;
          case 0: 
            (*raiz)->fb = -1;
            (*raiz)->altura++;
            break;
          case -1:
            avl_AuxFD(raiz);
            ok = 0;
            break;
        }
      }
    }
  }
  return ok;
}

int insereValor(AVL* raiz, int valor) {
  if(raiz == NULL) return 0;
  return insereValorRec(raiz, valor);
}

int removeValorRec(AVL* raiz, int valor) {
  int ok;
  if(raiz == NULL) return 0;
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
      NO* Filho = (*raiz)->esq;
      while(Filho->dir != NULL) {
        Filho = Filho->dir;
      }
      (*raiz)->info = Filho->info;
      Filho->info = valor;
      return removeValorRec(&(*raiz)->esq, valor);
    }
    return 1;
  } else if(valor < (*raiz)->info) {
    ok = removeValorRec(&(*raiz)->esq, valor);
    if(ok) {
      switch((*raiz)->fb) {
        case 1:
        case 0:
          (*raiz)->fb = -1;
          (*raiz)->altura = altura(*raiz);
          (*raiz)->fb = FB(*raiz);
          break;
        case -1:
        avl_AuxFD(raiz);
        break;
      }
    }
  } else if(valor > (*raiz)->info) {
    ok = removeValorRec(&(*raiz)->dir, valor);
    if(ok) {
      switch((*raiz)->fb) {
        case -1:
        case 0:
          (*raiz)->fb = -1;
          (*raiz)->altura = altura(*raiz);
          (*raiz)->fb = FB(*raiz);
          break;
        case 1:
          avl_AuxFE(raiz);
          break;
      }
    }
  }
  
  return ok;
}

int removeValor(AVL* raiz, int valor) {
  if(raiz == NULL || estaVazia(raiz)) {
    printf("A árvore está vazia ou não foi inicializada.\n");
    return 0;
  }
  return removeValorRec(raiz, valor);
}

int numeroNosRec(NO* raiz) {
  if(raiz == NULL) return 0;
  return 1 + numeroNosRec(raiz->esq) + numeroNosRec(raiz->dir);
}

int numeroNos(AVL* raiz) {
  if(raiz == NULL) return 0;
  if(estaVazia(raiz)) return 0;
  return numeroNosRec(*raiz);
}

#endif