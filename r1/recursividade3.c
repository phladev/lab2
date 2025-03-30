#include <stdio.h>

int somaIntervalo(int vet[], int ini, int fim) {
    if(ini > fim) {
        return 0;
    }

    return vet[fim] + somaIntervalo(vet, ini, fim - 1);
}

int main() {
    int vet[5] = {45, 21, 14, 92, 10};

    printf("Total: %d\n", somaIntervalo(vet, 0, 4));
    return 0;
}