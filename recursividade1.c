#include <stdio.h>


void imprimeCres(int num) {
    if(num == 6) {
        return;
    }
    printf("%d ", num);
    imprimeCres(num + 1);
}

void imprimeDes(int num) {
    if(num == 0) {
        return;
    }
    printf("%d ", num);
    imprimeDes(num - 1);
}

int main() {
    imprimeCres(1);
    printf("\n");
    imprimeDes(5);
    printf("\n");

    return 0;
}