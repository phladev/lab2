    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>


    void imprimeVetor(int *v, int n){
        for(int i=0;i<n;i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    void preencheVetor(int *v1, int *v2, int n1, int n2) {
        for(int i=0; i<n1; i++) {
            v1[i] = rand() % 100;
        }

        for(int i=0; i<n2; i++) {
            v2[i] = rand() % 100;
        }
    }

    int maiorElemento(int *v, int n) {
        int maior =  v[0];
        for(int i = 1; i < n; i++) {
            if(v[i] > maior) {
                maior = v[i];
            }
        }
        return maior;
    }

    int menorElemento(int *v, int n) {
        int menor = v[0];
        for(int i = 1; i < n; i++) {
            if(v[i] < menor) {
                menor = v[i];
            }
        }
        return menor;
    }

    float mediaEntreVetores(int *v1, int *v2, int n1, int n2) {
        float soma = 0;
        for(int i = 0; i<n1; i++){
            soma+=v1[i];
        }
        for(int i = 0; i<n2; i++){
            soma+=v2[i];
        }

        return soma/(n1+n2);
    }


    int main() {
        srand(time(NULL));
        int v1[5], v2[5];
        preencheVetor(v1, v2, 5, 5);
        printf("Vetor 1: ");
        imprimeVetor(v1, 5);

        printf("Maior elemento v1: %d\n", maiorElemento(v1, 5));
        printf("Menor elemento v1: %d\n", menorElemento(v1, 5));

        printf("Vetor 2: ");
        imprimeVetor(v2, 5);
        printf("Maior elemento v2: %d\n", maiorElemento(v2, 5));
        printf("Menor elemento v2: %d\n", menorElemento(v2, 5));

        printf("Média entre vetores: %.2f\n", mediaEntreVetores(v1, v2, 5, 5));
        return 0;
    }