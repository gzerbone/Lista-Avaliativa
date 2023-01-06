/*
Foi utilizado a lista, pois nao teria necessidade de trabalhar com a quantidade
de numeros armazenados na lista, alem de ser mais simples as implementacoes das
funcoes
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *next;
}No;

typedef struct{
    No *inicio;
    int tam;
}Raiz;

void Inicializacao(Raiz *lista)
{
    lista->inicio = NULL;
    lista->tam = 0;
}

void Inserir(Raiz *lista, int valor)
{
    No *novo = (No*)malloc(sizeof(No));
    novo->info = valor;
    novo->next = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}

void Imprimir(Raiz *lista)
{
    int i, tam = lista->tam;

    printf("\n[ ");

    for(i = tam; i > 0; i--)
    {
        printf("%d  ", lista->inicio->info);
        lista->inicio = lista->inicio->next;

        if(i!=1)
            printf("*  ");
    }

    printf("]\n");
}

int main()
{
    int valor, i, cont;

    Raiz lista;
    Inicializacao(&lista);

    printf("    Fatoracao Prima\n");
    printf("\nInsira o valor: ");
    scanf("%d", &valor);

    i = 2;
    while(valor != 1)
    {
        while(valor%i == 0)
        {
            Inserir(&lista, i);
            valor = valor/i;

            cont++;
        }

        i++;
    }

    if (cont == 0)
        Inserir(&lista, valor);

    Imprimir(&lista);

    return 0;
}

