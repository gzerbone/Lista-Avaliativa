#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int placa;
    int manobras;
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

void Imprimir(Raiz *lista)
{
    No *inicio = lista->inicio;

    printf("Carros estacionados: %d\n", lista->tam);

    while(inicio != NULL)
    {
        printf("\n[%d]:[%d]", inicio->placa, inicio->manobras);
        inicio = inicio->next;
    }
}

void push(Raiz *lista, int placa, int manobras)
{
        No *novo = (No*)malloc(sizeof(No));
        novo->placa = placa;
        novo->manobras = manobras;
        novo->next = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
}

void pop(Raiz *lista, int placa)
{
    system("cls");
    if(lista->inicio->placa == placa)
    {
        printf("Carro %d fora da garagem, foi manobrado %d vezes para a saida de outros carros.\n", lista->inicio->placa, lista->inicio->manobras);
        lista->inicio = lista->inicio->next;
        lista->tam--;
    }
    else
    {
        int tam=-1, mat[10][2], aux;

        aux = lista->tam - 1;

        while(lista->inicio->placa != placa)
        {
            tam++;
            mat[tam][0] = lista->inicio->placa;
            mat[tam][1] = lista->inicio->manobras + 1;

            lista->inicio = lista->inicio->next;
            lista->tam--;

            if(tam == aux)
                break;
        }

        if(tam != aux)
        {
            printf("Carro %d fora da garagem, foi manobrado %d vezes para a saida de outros carros.\n", lista->inicio->placa, lista->inicio->manobras);
            lista->inicio = lista->inicio->next;
            lista->tam--;

            for(tam; tam>=0; tam--)
                push(lista, mat[tam][0], mat[tam][1]);
        }
        else
        {
            printf("Carro nao encontrado!\n");

            for(tam; tam>=0; tam--)
                push(lista, mat[tam][0], mat[tam][1]-1);
        }

    }
    system("pause");
}

int main(){
    Raiz lista;
    Inicializacao(&lista);

    int option, placa, manobras=0;
    char escolha;

    while(option != 3)
    {
        system("cls");
        printf("    ESTACIONAMENTO\n\n");

        Imprimir(&lista);

        printf("\n\n1-> Modificar\n2-> SAIR\n\n-> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Insira E, para entrada, ou um S para saida e placa respectivamente: ");
            fflush(stdin);
            scanf("%c %d", &escolha, &placa);
            if(escolha == 'E'){
                system("cls");
                if(lista.tam == 10)
                {
                    printf("Estacionamento cheio!\n");
                    system("pause");
                }
                else
                {

                    push(&lista, placa, manobras);
                    printf("Carro estacionado!\n");
                }
                system("pause");
            }
            else if(escolha == 'S')
                pop(&lista, placa);
            else{
                system("cls");
                printf("OPCAO INVALIDA\n");
                system("pause");
            }
            break;

        case 2:
            system("cls");
            printf("Saindo...\n");
            break;

        default:
            break;
        }
    }

    return 0;
}
