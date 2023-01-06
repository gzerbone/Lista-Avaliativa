
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct pessoa{
    int matricula;
    char nome[50];
    float nota;
}Pessoa;

void quick_sort(Pessoa *N, int left, int right){
    int i, j, x, y;

    i = left;
    j = right;
    x = N[(left + right) / 2].matricula;

    while(i <= j) {
        while(N[i].matricula < x && i < right) {
            i++;
        }
        while(N[j].matricula > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = N[i].matricula;
            N[i].matricula = N[j].matricula;
            N[j].matricula = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(N, left, j);
    }
    if(i < right) {
        quick_sort(N, i, right);
    }
}

int main()
{
    int i;
    Pessoa N[MAX];

    printf("***** Digite %d elementos *****\n", MAX);

    for(i = 0; i < MAX; i++){
        printf("ELEMENTO %d\n\n",i+1);
        printf("Digite a matricula: ");
        scanf("%d", &N[i].matricula);
        printf("Digite nome: ");
        scanf("%s", &N[i].nome);
        printf("Digite o nota: ");
        scanf("%f", &N[i].nota);
        printf("\n");
    }

 quick_sort(N, 0, MAX - 1);
    printf("\n----------------------------------------------\n");
    printf("Depois de Ordenado:\n");
    for(i = 0; i < MAX; i++){
        printf("\nMatricula: %d ", N[i].matricula);
        printf("\nNome: %s ", N[i].nome);
        printf("\nNota: %.2f ", N[i].nota);
        printf("\n\n ");
    }
    return 0;
}
