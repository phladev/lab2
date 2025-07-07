#include <stdio.h>
#include "Patricia.h"

void binary(int n){
	if(n<2) 
          printf("%d ", n%2);
	else{
          binary(n/2);
	  printf("%d ", n%2);
	}
}

int main(){

    int valoresLivro[7] = {18, 19, 24, 33, 40, 54, 34};
    //char valoresLivroChar[7] = {'B', 'C', 'H', 'J', 'Q', 'W', 'K'};

    ArvorePat P = NULL;
    int x, i;
    
    for(i=0; i<7; i++){
        P = Insere(valoresLivro[i], &P);
        imprimePatricia(P);
    }

    // x = 5;
    // printf("%d em binario: ", x); binary(x); printf("\n");
    // P = Insere(x, &P);
    // imprimePatricia(P);

    // x = 10;
    // printf("%d em binario: ", x); binary(x); printf("\n");
    // P = Insere(x, &P);
    // imprimePatricia(P);

    // x = 11;
    // printf("%d em binario: ", x); binary(x); printf("\n");
    // P = Insere(x, &P);
    // imprimePatricia(P);

    // x = 12;
    // printf("%d em binario: ", x); binary(x); printf("\n");
    // P = Insere(x, &P);
    // imprimePatricia(P);

    printf("\n\nBusca\n");
    x = 9;
    printf("%d em binario: ", x); binary(x); printf("\n");
    Pesquisa(x, P);
    
    x = 11;
    printf("%d em binario: ", x); binary(x); printf("\n");
    Pesquisa(x, P);


    printf("\n\nResultado:\n");
    imprimePatricia(P);


    return 0;
}
