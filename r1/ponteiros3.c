#include <stdio.h>
#include <string.h>


typedef struct Aluno {
    char nome[20];
    int matricula;
    float nota;
} Aluno;

int indexMaiorNota(Aluno *v, int n){
    int maiorNota = v[0].nota;
    int index = 0;
    for(int i =1; i< n; i++){
        if(v[i].nota > maiorNota) {
            maiorNota = v[i].nota;
            index = i;
        }
    }

    return index;
}

int indexMenorNota(Aluno *v, int n){
    int menorNota = v[0].nota;
    int index = 0;
    for(int i =1; i< n; i++){
        if(v[i].nota < menorNota) {
            menorNota = v[i].nota;
            index = i;
        }
    }

    return index;
}

int main() {
    Aluno alunos[3];
    for(int i = 0; i<3; i++) {
        fgets(alunos[i].nome, 20, stdin);
        alunos[i].nome[strlen(alunos[i].nome) - 1] = '\0';
        scanf(" %d", &alunos[i].matricula);
        scanf("%f", &alunos[i].nota);
        getchar();
    }

    printf("Dados aluno menor nota: \n");
    printf("Nome: %s Matricula: %d Nota: %.2f \n", alunos[indexMenorNota(alunos, 3)].nome,
    alunos[indexMenorNota(alunos, 3)].matricula, alunos[indexMenorNota(alunos, 3)].nota);

    printf("Dados aluno Maior nota: \n");
    printf("Nome: %s Matricula: %d Nota: %.2f \n", alunos[indexMaiorNota(alunos, 3)].nome,
    alunos[indexMaiorNota(alunos, 3)].matricula, alunos[indexMaiorNota(alunos, 3)].nota);

    return 0;
}