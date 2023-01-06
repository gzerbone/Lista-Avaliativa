#include <stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct pessoa{
    int matricula;
    char nome[50];
    float nota;
}Pessoa;

void insertionSort(Pessoa list[], int n, int resposta){
    int aux;

    if(resposta == 1){
        for(int i=0;i<n;i++){
            aux=list[i].matricula;
            for(int j=i;(j>0)&&(aux<list[j-1].matricula);j--){
                list[j].matricula = list[j-1].matricula ;
                list[j-1].matricula = aux;
            }
        }
    }

    if(resposta == 2){
        for(int i=0;i<n;i++){
            aux=list[i].nota;
            for(int j=i;(j>0)&&(aux<list[j-1].nota);j--){
                list[j].nota = list[j-1].nota ;
                list[j-1].nota = aux;
            }
        }
    }
}

int main(){
    Pessoa N[MAX];
    int i, resposta=0;

    printf("***** Digite %d elementos *****\n", MAX);
    for (i = 0; i < MAX; i++){
        printf("ELEMENTO %d\n\n",i+1);
        printf("Digite a matricula: ");
        scanf("%d", &N[i].matricula);
        printf("Digite nome: ");
        scanf("%s", &N[i].nome);
        printf("Digite o nota: ");
        scanf("%f", &N[i].nota);
        printf("\n");
    }

    printf("\n----------------------------------------------\n");
    printf("Escolha qual sera a ordem da ordenacao:\n1-Matricula\n2-Nota\n->");
    scanf("%d", &resposta);

    insertionSort(N, MAX, resposta);
    printf("\n----------------------------------------------\n");
    printf("Depois de Ordenado:\n");

    for (i = 0; i < MAX; i++){
        printf("\nMatricula: %d ", N[i].matricula);
        printf("\nNome: %s ", N[i].nome);
        printf("\nNota: %.2f ", N[i].nota);
        printf("\n\n ");
    }

    return 0;

}
