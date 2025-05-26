#ifndef ABP_ALUNO_H
#define ABP_ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
  char nome[50];
  int matricula;
  double nota;
} Aluno;

typedef struct NO {
  Aluno info;
  struct NO *esq;
  struct NO *dir;
} NO;

typedef struct NO* ABP_ALUNO; 

ABP_ALUNO* criaABP() {
  ABP_ALUNO* raiz = (ABP_ALUNO*)malloc(sizeof(ABP_ALUNO));
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

void destroiABP(ABP_ALUNO* raiz) {
  if(raiz != NULL) {
    destroiRec(*raiz);
    free(raiz);
  }
}

int estaVazia(ABP_ALUNO* raiz) {
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

int comparaAluno(const Aluno* a1, const Aluno* a2) {
  int cmp = strcmp(a1->nome, a2->nome);
  if (cmp < 0) return -1;
  if (cmp > 0) return 1;
  return 0;
}

int insereRec(NO** raiz, Aluno valor) {
  if(*raiz == NULL) {
    NO* novo = alocaNO();
    if(novo == NULL) return 0;
    novo->info = valor;
    *raiz = novo;
    return 1;
  } else {
    int cmp = comparaAluno(&valor, &(*raiz)->info);
    if(cmp == 0) {
      return 0;
    } else if(cmp < 0) {
      return insereRec(&(*raiz)->esq, valor);
    } else {
      return insereRec(&(*raiz)->dir, valor);
    }
  }
  return 1;
}

int insereValor(ABP_ALUNO* raiz, Aluno valor) {
  if(raiz == NULL) return 0;
  return insereRec(raiz, valor);
}

int pesquisaRec(NO** raiz, Aluno valor) {
  if(*raiz == NULL) return 0;
  int cmp = comparaAluno(&valor, &(*raiz)->info);
  if(cmp == 0) {
    printf("Aluno encontrado:\nNome: %s\nMatricula: %d\nNota: %.2f\n", (*raiz)->info.nome, (*raiz)->info.matricula, (*raiz)->info.nota);
    return 1;
  } else if(cmp < 0) {
    return pesquisaRec(&(*raiz)->esq, valor);
  } else {
    return pesquisaRec(&(*raiz)->dir, valor);
  }
}

int pesquisaValor(ABP_ALUNO* raiz, Aluno valor) {
  if(raiz == NULL) return 0;
  if(estaVazia(raiz)) return 0;
  return pesquisaRec(raiz, valor);
}

int removeRecPorNome(NO** raiz, const char* nome) {
  if (*raiz == NULL) return 0;
  int cmp = strcmp(nome, (*raiz)->info.nome);
  if (cmp == 0) {
    NO *aux;
    if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
      free(*raiz);
      *raiz = NULL;
    } else if ((*raiz)->esq == NULL) {
      aux = *raiz;
      *raiz = (*raiz)->dir;
      free(aux);
    } else if ((*raiz)->dir == NULL) {
      aux = *raiz;
      *raiz = (*raiz)->esq;
      free(aux);
    } else {
      NO *Filho = (*raiz)->esq;
      while (Filho->dir != NULL) {
        Filho = Filho->dir;
      }
      strcpy((*raiz)->info.nome, Filho->info.nome);
      (*raiz)->info.matricula = Filho->info.matricula;
      (*raiz)->info.nota = Filho->info.nota;
      removeRecPorNome(&(*raiz)->esq, Filho->info.nome);
    }
    return 1;
  } else if (cmp < 0) {
    return removeRecPorNome(&(*raiz)->esq, nome);
  } else {
    return removeRecPorNome(&(*raiz)->dir, nome);
  }
}

int removePorNome(ABP_ALUNO* raiz, const char* nome) {
  if (raiz == NULL || *raiz == NULL) return 0;
  return removeRecPorNome(raiz, nome);
}

void em_ordem(NO *raiz, int nivel) {
  if(raiz != NULL) {
    em_ordem(raiz->esq, nivel + 1);
    printf("Nivel %d: Nome: %s, Matricula: %d, Nota: %.2f\n", nivel, raiz->info.nome, raiz->info.matricula, raiz->info.nota);
    em_ordem(raiz->dir, nivel + 1);
  }
}

void imprimeEmOrdem(ABP_ALUNO* raiz) {
  if(raiz == NULL) return;
  if(estaVazia(raiz)) {
    printf("Arvore vazia\n");
    return;
  }
  em_ordem(*raiz, 0);
}

void maiorNotaRec(NO* raiz, double* maiorNota, Aluno* alunoMaior) {
  if (raiz != NULL) {
    if (raiz->info.nota > *maiorNota) {
      *maiorNota = raiz->info.nota;
      *alunoMaior = raiz->info;
    }
    maiorNotaRec(raiz->esq, maiorNota, alunoMaior);
    maiorNotaRec(raiz->dir, maiorNota, alunoMaior);
  }
}

void imprimeAlunoMaiorNota(ABP_ALUNO* raiz) {
  if (raiz == NULL || *raiz == NULL) {
    printf("Arvore vazia\n");
    return;
  }
  double maiorNota = (*raiz)->info.nota;
  Aluno alunoMaior = (*raiz)->info;
  maiorNotaRec(*raiz, &maiorNota, &alunoMaior);
  printf("Aluno com maior nota:\nNome: %s\nMatricula: %d\nNota: %.2f\n", alunoMaior.nome, alunoMaior.matricula, alunoMaior.nota);
}

void menorNotaRec(NO* raiz, double* menorNota, Aluno* alunoMenor) {
  if (raiz != NULL) {
    if (raiz->info.nota < *menorNota) {
      *menorNota = raiz->info.nota;
      *alunoMenor = raiz->info;
    }
    menorNotaRec(raiz->esq, menorNota, alunoMenor);
    menorNotaRec(raiz->dir, menorNota, alunoMenor);
  }
}

void imprimeAlunoMenorNota(ABP_ALUNO* raiz) {
  if (raiz == NULL || *raiz == NULL) {
    printf("Arvore vazia\n");
    return;
  }
  double menorNota = (*raiz)->info.nota;
  Aluno alunoMenor = (*raiz)->info;
  menorNotaRec(*raiz, &menorNota, &alunoMenor);
  printf("Aluno com menor nota:\nNome: %s\nMatricula: %d\nNota: %.2f\n", alunoMenor.nome, alunoMenor.matricula, alunoMenor.nota);
}

#endif