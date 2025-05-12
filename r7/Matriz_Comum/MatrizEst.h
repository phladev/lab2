#ifndef MATRIZEST_H
#define MATRIZEST_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
  int lin, col;
  int dados[MAX][MAX];
}MatrizEst;

MatrizEst* criaMatriz(int lin, int col) {
  MatrizEst* m = (MatrizEst*)calloc(1, sizeof(MatrizEst));
  if(m != NULL) {
    if(lin <= 0 || lin > MAX || col <= 0 || col > MAX) {
      return NULL;
    }
    m->lin = lin;
    m->col = col;
  }
  return m;
}

void destroMatriz(MatrizEst* m) {
  if(m != NULL) {
    free(m);
  }
}

int insereElem(MatrizEst* m, int lin, int col, int valor) {
  if(m == NULL || lin < 0 || lin >= m->lin || col < 0 || col >= m->col) {
    return -1;
  }
  m->dados[lin][col] = valor;
  return 0;
}

int procuraElem(MatrizEst* m, int lin, int col) {
  if(m == NULL || lin < 0 || lin >= m->lin || col < 0 || col >= m->col) {
    return -1;
  }
  return m->dados[lin][col];
}

void imprime(MatrizEst* m) {
  if(m != NULL) {
    for(int i = 0; i < m->lin; i++) {
      for(int j = 0; j < m->col; j++) {
        printf("%d ", m->dados[i][j]);
      }
      printf("\n");
    }
  }
}

MatrizEst* criaTransposta(MatrizEst* m) {
  if(m == NULL) {
    return NULL;
  }
  MatrizEst* transposta = criaMatriz(m->col, m->lin);
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      transposta->dados[j][i] = m->dados[i][j];
    }
  }
  return transposta;
}

int isQuadrada(MatrizEst* m) {
  if(m == NULL) {
    return -1;
  }
  return m->lin == m->col;
}

int isSimetrica(MatrizEst* m) {
  if(m == NULL || !isQuadrada(m)) {
    return -1;
  }
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      if(m->dados[i][j] != m->dados[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

MatrizEst* criaMatrizTriangularSup(MatrizEst* m) {
  if(m == NULL || !isQuadrada(m)) {
    return NULL;
  }
  MatrizEst* triangularSup = criaMatriz(m->lin, m->col);
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      if(i <= j) {
        triangularSup->dados[i][j] = m->dados[i][j];
      }
    }
  }
  return triangularSup;
}

MatrizEst* criaMatrizTriangularInf(MatrizEst* m) {
  if(m == NULL || !isQuadrada(m)) {
    return NULL;
  }
  MatrizEst* triangularInf = criaMatriz(m->lin, m->col);
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      if(i >= j) {
        triangularInf->dados[i][j] = m->dados[i][j];
      }
    }
  }
  return triangularInf;
}

MatrizEst* criaMatrizDiagonal(MatrizEst* m) {
  if(m == NULL || !isQuadrada(m)) {
    return NULL;
  }
  MatrizEst* diagonal = criaMatriz(m->lin, m->col);
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      if(i == j) {
        diagonal->dados[i][j] = m->dados[i][j];
      }
    }
  }
  return diagonal;
}


#endif