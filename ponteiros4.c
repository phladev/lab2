#include <stdio.h>
#include <math.h>


int raizes(float A, float B, float C, float* X1, float * X2) {
    float delta = pow(B, 2) - (4*A*C);
    if(delta < 0) {
        return 0;
    }
    *X1 = (-B + sqrt(delta)) / (2*A);
    *X2 = (-B - sqrt(delta)) / (2*A);
    if(delta == 0) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    float A, B, C, X1=0, X2=0;
    scanf("%f %f %f", &A, &B, &C);
    int numRaizes = raizes(A, B, C, &X1, &X2);

    printf("Numero raizes: %d | x1: %.2f | x2: %.2f\n", numRaizes, X1, X2);
    return 0;
}