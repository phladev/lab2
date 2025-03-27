#include <stdio.h>

void imprimeLetraDesc(char vet[], int ini, int fim) {
    if(ini > fim) {
        return;
    }

    printf("%c ", vet[fim]);
    imprimeLetraDesc(vet, ini, fim -1);
}

int main() {
    char vetor[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    imprimeLetraDesc(vetor, 0, 7);
    printf("\n");
    return 0;
}