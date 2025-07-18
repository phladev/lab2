#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"

int main(){
    ArvoreB *B = criaArvoreB();
    int valores[21] = {20, 10, 40, 50, 30, 55, 3, 11, 4, 28, 36, 33, 52, 17, 25, 13, 45, 9, 43, 8, 48};
    int remover[17] = {45, 30, 28, 50, 8, 10, 4, 20, 40, 55, 17, 33, 11, 36, 3, 9, 52};

    int i;
    Registro r;
    char c;

    for(i=0; i<21; i++){
        r.chave = valores[i];
        insereArvoreB(B, r);
    }  

    printf("\n\nBusca:\n");
    for(i=0; i<21; i++){
        r.chave = valores[i];
        pesquisaArvoreB(B, &r);
    }

    printf("\n\nResultado:\n");
    imprimeArvoreB(B);

    for(i=0; i<17; i++){
        r.chave = remover[i];
        removeArvoreB(B, r);
    }  
    
    printf("\n\nResultado depois remocoes:\n");
    imprimeArvoreB(B);

    destroiArvoreB(B);
    return 0;
}