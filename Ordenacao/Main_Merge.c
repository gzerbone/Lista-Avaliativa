#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct pessoa{
    int matricula;
    char nome[50];
    float nota;
}Pessoa;

void merge_sort(Pessoa *N, Pessoa *N_AUX, int i, int j, int resposta){
    int mid = (i + j) / 2;
    int left = i;
    int right = mid + 1;
    int k;

    if (j <= i) {
        return;
    }
    merge_sort(N, N_AUX, i, mid, resposta);
    merge_sort(N, N_AUX, mid + 1, j, resposta);

    if(resposta == 1){
        for(k = i; k <= j; k++){
            if(left == mid + 1){
                N_AUX[k].matricula = N[right].matricula;
                right++;
            }else if(right == j + 1){
                N_AUX[k].matricula = N[left].matricula;
                left++;
            }else if(N[left].matricula < N[right].matricula){
                N_AUX[k].matricula = N[left].matricula;
                left++;
            }else{
                N_AUX[k].matricula = N[right].matricula;
                right++;
            }
        }

        for(k = i; k <= j; k++){
            N[k].matricula = N_AUX[k].matricula;
        }
    }

    else if(resposta == 2){
        for(k = i; k <= j; k++){
            if(left == mid + 1){
                N_AUX[k].nota = N[right].nota;
                right++;
            }else if(right == j + 1){
                N_AUX[k].nota = N[left].nota;
                left++;
            }else if(N[left].nota < N[right].nota){
                N_AUX[k].nota = N[left].nota;
                left++;
            }else{
                N_AUX[k].nota = N[right].nota;
                right++;
            }
        }

        for(k = i; k <= j; k++){
            N[k].nota = N_AUX[k].nota;
        }
    }
}
int main(){
    Pessoa N[MAX];
    Pessoa N_AUX[MAX];
    int i, resposta = 0;

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

    merge_sort(N, N_AUX, 0, MAX - 1, resposta);
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
