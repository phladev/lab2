#include <stdio.h>

int multiplicacao(int m, int n) {
    if(n == 0) {
        return 0;
    }

    return m + multiplicacao(m, n-1);
}


int main() {
    int m1 = multiplicacao(5,4);
    int m2 = multiplicacao(9,9);

    printf("Resultado1: %d\n", m1);
    printf("Resultado2: %d\n", m2);
    return 0;
}