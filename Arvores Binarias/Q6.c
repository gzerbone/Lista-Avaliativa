#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int info;
    float info;
    char info;
}dataType;

struct nodetype{
	dataType info;
	struct nodetype *left;
	struct nodetype *right;
	struct nodetype *father;
};
typedef struct nodetype Node;

typedef struct
{
    int *vet;
    int size;
    int cap;
} Heap;

//incializar o vetor com malloc, pra ter tudo no vetor == 0
void inicializar(Heap *H, int alt)
{
     //tendo a raiz na alt 0
    int qtd = pow(2, (alt+1)) - 1;

    H->vet = malloc(qtd * sizeof(int));
    H->cap = alt;
    H->size = 0;
}

void Verificar(Heap *H)
{
    int i, cap = pow(2, (H->cap+1)) - 1;
    int vazio, inMaior, inMenor, maior, menor;

    inMaior = inMenor = 0;
    maior = menor = H->vet[0];

    for(i=0; i<H->size; i++)
    {
        if(H->vet == 0)
            vazio = 1;

        if(H->vet[i] < menor && H->vet != 0)
        {
            menor = H->vet[i];
            inMenor = i;
        }

        if(H->vet[i] > maior)
        {
            maior = H->vet[i];
            inMaior = i;
        }
    }

    if(inMaior == 0) //MaxHeap
        return 1;
    else if(inMenor == 0) //MinHeap
        return -1;
    else
        return 0;
}
