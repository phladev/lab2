#include <stdio.h>


int negativos(float *vet, int N) {
    int neg = 0;
    for(int i=0; i<N; i++) {
        if(vet[i] < 0) {
            neg++;
        }
    }

    return neg;
}

int main() {
    float vet[5];
    for(int i=0; i<5; i++) {
        scanf("%f", &vet[i]);
    }
    int neg = negativos(vet, 5);

    printf("tem %d números negativos\n", neg);
    return 0;
}