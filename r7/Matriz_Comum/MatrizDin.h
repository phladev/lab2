#ifndef MATRIZDIN_H
#define MATRIZDIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int lin, col;
  int **dados;
}MatrizDin;

MatrizDin* criaMatriz(int lin, int col) {
  MatrizDin* m = (MatrizDin*)calloc(1, sizeof(MatrizDin));
  if(m != NULL) {
    if(lin <= 0 || col <= 0) {
      return NULL;
    }
    m->lin = lin;
    m->col = col;
    m->dados = (int**)malloc(lin * sizeof(int*));
    for(int i = 0; i < lin; i++) {
      m->dados[i] = (int*)malloc(col * sizeof(int));
    }
  }
  return m;
}

void destroMatriz(MatrizDin* m) {
  if(m != NULL) {
    for(int i = 0; i < m->lin; i++) {
      free(m->dados[i]);
    }
    free(m->dados);
    free(m);
  }
}

int insereElem(MatrizDin* m, int lin, int col, int valor) {
  if(m == NULL || lin < 0 || lin >= m->lin || col < 0 || col >= m->col) {
    return -1;
  }
  m->dados[lin][col] = valor;
  return 0;
}

int procuraElem(MatrizDin* m, int lin, int col) {
  if(m == NULL || lin < 0 || lin >= m->lin || col < 0 || col >= m->col) {
    return -1;
  }
  return m->dados[lin][col];
}

void imprime(MatrizDin* m) {
  if(m != NULL) {
    for(int i = 0; i < m->lin; i++) {
      for(int j = 0; j < m->col; j++) {
        printf("%d ", m->dados[i][j]);
      }
      printf("\n");
    }
  }
}

MatrizDin* criaTransposta(MatrizDin* m) {
  if(m == NULL) {
    return NULL;
  }
  MatrizDin* transposta = criaMatriz(m->col, m->lin);
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      transposta->dados[j][i] = m->dados[i][j];
    }
  }
  return transposta;
}

int isQuadrada(MatrizDin* m) {
  if(m == NULL) {
    return -1;
  }
  return m->lin == m->col;
}

int isSimetrica(MatrizDin* m) {
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

MatrizDin* criaMatrizTriangularSup(MatrizDin* m) {
  if(m == NULL || !isQuadrada(m)) {
    return NULL;
  }
  MatrizDin* triangularSup = criaMatriz(m->lin, m->col);
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      if(i <= j) {
        triangularSup->dados[i][j] = m->dados[i][j];
      }
    }
  }
  return triangularSup;
}

MatrizDin* criaMatrizTriangularInf(MatrizDin* m) {
  if(m == NULL || !isQuadrada(m)) {
    return NULL;
  }
  MatrizDin* triangularInf = criaMatriz(m->lin, m->col);
  for(int i = 0; i < m->lin; i++) {
    for(int j = 0; j < m->col; j++) {
      if(i >= j) {
        triangularInf->dados[i][j] = m->dados[i][j];
      }
    }
  }
  return triangularInf;
}

MatrizDin* criaMatrizDiagonal(MatrizDin* m) {
  if(m == NULL || !isQuadrada(m)) {
    return NULL;
  }
  MatrizDin* diagonal = criaMatriz(m->lin, m->col);
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