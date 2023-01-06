#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct pessoa{
    int matricula;
    char nome[50];
    float nota;
}Pessoa;

int main(){
    Pessoa N[MAX];

    int i,j,root;
    int t,x;
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
    for(i=0;i<MAX;i++){
        x=i;
        do{
            root = (x - 1) / 2;
            if (N[root].matricula < N[x].matricula){
                t = N[root].matricula;
                N[root].matricula = N[x].matricula;
                N[x].matricula = t;
            }
            x = root;
        }while(x != 0);
    }

    for (j = MAX - 1; j >= 0; j--){
        t = N[0].matricula;
        N[0].matricula = N[j].matricula;
        N[j].matricula = t;
        root = 0;

        do{
            x = 2 * root + 1;
            if ((N[x].matricula < N[x + 1].matricula) && x < j-1)
                x++;
            if (N[root].matricula<N[x].matricula && x<j){
                t = N[root].matricula;
                N[root].matricula = N[x].matricula;
                N[x].matricula = t;
            }
            root = x;
        }while(x < j);
    }
    printf("\n----------------------------------------------\n");
    printf("\nDepois da Ordenacao\n");
    for (i = 0; i < MAX; i++){
        printf("\nMatricula: %d ", N[i].matricula);
        printf("\nNome: %s ", N[i].nome);
        printf("\nNota: %.2f ", N[i].nota);
        printf("\n\n ");
    }
    return 0;
}

