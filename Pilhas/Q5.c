#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int topo;
    char vet[100];
} Pilha;

void push(Pilha *p, char caractere)
{
    p->topo++;
    p->vet[p->topo] = caractere;
}

char pop(Pilha *p)
{
    char caractere;
    caractere = p->vet[p->topo];
    p->vet[p->topo] = ' ';
    p->topo--;

    return caractere;
}

void Fechamento(Pilha p, char str[])
{
    int tam=0;
    char caractere;
    p.topo = -1;

    while(str[tam] != '\0')
    {
        if(str[tam] == '(' || str[tam] == '{' || str[tam] == '[')
        {
            caractere = str[tam];

            switch (caractere)
            {
            case '(':
                push(&p, ')');
                break;

            case '{':
                push(&p, '}');
                break;

            case '[':
                push(&p, ']');
                break;

            default:
                break;
            }
        }

        if(str[tam] == ')' || str[tam] == '}' || str[tam] == ']')
        {
            if(pop(&p) != str[tam])
            {
                printf("\nA expressao algebrica NAO possui a combinacao correta de parenteses, colchetes e chaves!\n");
                return;
            }
        }

        tam++;
    }

    printf("\nA expressao algebrica possui a combinacao correta de parenteses, colchetes e chaves!\n");
}

int main()
{
    Pilha p;
    char str[100];

    printf("Insira a operacao: ");
	gets(str);

    Fechamento(p, str);

    return 0;
}
