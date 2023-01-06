#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    LIST lista;
    NODE *aux;

    initialize(&lista);

    insertFirst(&lista, 't');
    insertFirst(&lista, 'e');
    insertFirst(&lista, 'n');
    insertFirst(&lista, 'e');
    insertFirst(&lista, 't');

    printf("eh palindromo iterativo ? retorna = %d\n", ehPalindromoIterativa(&lista));
    printf("eh palindromo recursivo ? retorna = %d\n", ehPalindromoRecursiva(&lista, lista.first, findLast(&lista)));

    return 0;
}

