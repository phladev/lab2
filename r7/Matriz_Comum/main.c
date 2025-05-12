#include <stdio.h>
#include "MatrizEst.h"

int main() {
  MatrizEst* m = criaMatriz(3, 3);
  if (m == NULL) {
    printf("Erro ao criar matriz.\n");
    return -1;
  }

  insereElem(m, 0, 0, 1);
  insereElem(m, 0, 1, 2);
  insereElem(m, 0, 2, 3);
  insereElem(m, 1, 0, 4);
  insereElem(m, 1, 1, 5);
  insereElem(m, 1, 2, 6);
  insereElem(m, 2, 0, 7);
  insereElem(m, 2, 1, 8);
  insereElem(m, 2, 2, 9);

  printf("Matriz é simetrica? %s\n", isSimetrica(m) ? "Sim" : "Não");
  printf("Matriz é quadrada? %s\n", isQuadrada(m) ? "Sim" : "Não");

  printf("Matriz original:\n");
  imprime(m);

  MatrizEst* transposta = criaTransposta(m);
  MatrizEst* triangularSup = criaMatrizTriangularSup(m);
  MatrizEst* triangularInf = criaMatrizTriangularInf(m);
  MatrizEst* diagonal = criaMatrizDiagonal(m);

  printf("Matriz transposta:\n");
  imprime(transposta);
  printf("Matriz triangular superior:\n");
  imprime(triangularSup);
  printf("Matriz triangular inferior:\n");
  imprime(triangularInf);
  printf("Matriz diagonal:\n");
  imprime(diagonal);

  destroMatriz(m);
  destroMatriz(transposta);
  destroMatriz(triangularSup);
  destroMatriz(triangularInf);
  destroMatriz(diagonal);
  return 0;
}