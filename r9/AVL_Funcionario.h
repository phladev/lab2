#ifndef AVL_FUNCIONARIO_H
#define AVL_FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct funcionario {
  int ano_contratacao;
  char nome[50];
  double salario;
} Funcionario;

typedef struct NO {
  Funcionario info;
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

int pesquisaRec(AVL* raiz, double chave) {
  if(*raiz == NULL) return 0;
  if((*raiz)->info.salario == chave) {
    printf("Funcionário encontrado:\n");
    printf("Nome: %s\n", (*raiz)->info.nome);
    printf("Ano de Contratação: %d\n", (*raiz)->info.ano_contratacao);
    printf("Salário: %.2f\n", (*raiz)->info.salario);
    return 1;
  }
  if(chave < (*raiz)->info.salario) {
    return pesquisaRec(&(*raiz)->esq, chave);
  } else {
    return pesquisaRec(&(*raiz)->dir, chave);
  }
}

int pesquisa(AVL* raiz, double chave) {
  if (raiz == NULL || estaVazia(raiz)) return 0;
  return pesquisaRec(raiz, chave);
}

int funcionarioMaiorSalario(AVL* raiz) {
  if (raiz == NULL || estaVazia(raiz)) return 0;
  NO* atual = *raiz;
  while (atual->dir != NULL) {
    atual = atual->dir;
  }
  printf("Funcionário com maior salário:\n");
  printf("Nome: %s\n", atual->info.nome);
  printf("Ano de Contratação: %d\n", atual->info.ano_contratacao);
  printf("Salário: %.2f\n", atual->info.salario);
  return 1;
}

int funcionarioMenorSalario(AVL* raiz) {
  if (raiz == NULL || estaVazia(raiz)) return 0;
  NO* atual = *raiz;
  while (atual->esq != NULL) {
    atual = atual->esq;
  }
  printf("Funcionário com menor salário:\n");
  printf("Nome: %s\n", atual->info.nome);
  printf("Ano de Contratação: %d\n", atual->info.ano_contratacao);
  printf("Salário: %.2f\n", atual->info.salario);
  return 1;
}

void em_ordem(NO* raiz, int nivel) {
  if (raiz == NULL) return;
  em_ordem(raiz->esq, nivel + 1);
  printf("Nivel %d: %s (Ano de Contratacao: %d, Salario: %.2f)\n", nivel, raiz->info.nome, raiz->info.ano_contratacao, raiz->info.salario);
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

int insereValorRec(AVL* raiz, Funcionario valor) {
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
    if((*raiz)->info.salario == valor.salario) {
      printf("Funcionário com salário %.2lf já existe na árvore.\n", valor.salario);
      return 0;
    } else if(valor.salario < (*raiz)->info.salario) {
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
    } else if(valor.salario > (*raiz)->info.salario) {
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

int insereValor(AVL* raiz, Funcionario valor) {
  if(raiz == NULL) return 0;
  return insereValorRec(raiz, valor);
}

int removeValorRec(AVL* raiz, const char* nome) {
  if (raiz == NULL || *raiz == NULL) return 0;
  int ok = 0;
  int cmp = strcmp(nome, (*raiz)->info.nome);
  if (cmp < 0) {
    ok = removeValorRec(&(*raiz)->esq, nome);
    if (ok) {
      (*raiz)->altura = altura(*raiz);
      (*raiz)->fb = FB(*raiz);
      if ((*raiz)->fb == -2) {
        if (FB((*raiz)->dir) <= 0)
          rotacaoSimplesEsquerda(raiz);
        else
          rotacaoDuplaDirEsq(raiz);
      }
    }
  } else if (cmp > 0) {
    ok = removeValorRec(&(*raiz)->dir, nome);
    if (ok) {
      (*raiz)->altura = altura(*raiz);
      (*raiz)->fb = FB(*raiz);
      if ((*raiz)->fb == 2) {
        if (FB((*raiz)->esq) >= 0)
          rotacaoSimplesDireita(raiz);
        else
          rotacaoDuplaEsqDir(raiz);
      }
    }
  } else {
    NO* temp = *raiz;
    if ((*raiz)->esq == NULL) {
      *raiz = (*raiz)->dir;
      free(temp);
      return 1;
    } else if ((*raiz)->dir == NULL) {
      *raiz = (*raiz)->esq;
      free(temp);
      return 1;
    } else {
      NO* maior = (*raiz)->esq;
      while (maior->dir != NULL)
        maior = maior->dir;
      (*raiz)->info = maior->info;
      ok = removeValorRec(&(*raiz)->esq, maior->info.nome);
      if (ok) {
        (*raiz)->altura = altura(*raiz);
        (*raiz)->fb = FB(*raiz);
        if ((*raiz)->fb == -2) {
          if (FB((*raiz)->dir) <= 0)
            rotacaoSimplesEsquerda(raiz);
          else
            rotacaoDuplaDirEsq(raiz);
        }
      }
      return 1;
    }
  }
  if (*raiz != NULL) {
    (*raiz)->altura = altura(*raiz);
    (*raiz)->fb = FB(*raiz);
  }
  return ok;
}

int removeValor(AVL* raiz, const char* nome) {
  if (raiz == NULL || estaVazia(raiz)) {
    return 0;
  }
  return removeValorRec(raiz, nome);
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