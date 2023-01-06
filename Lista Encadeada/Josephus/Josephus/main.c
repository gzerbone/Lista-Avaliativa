#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

int main()
{
    LIST lista;
    NODE* aux;

    char *palavra1 = "A";
    char *palavra2 = "B";
    char *palavra3 = "C";
    char *palavra4 = "D";
    char *palavra5 = "E";
    char *palavra6 = "F";
    char *palavra7 = "G";
    char *palavra8 = "H";

    initialize(&lista);

    insertFirst(&lista, palavra8);
    insertFirst(&lista, palavra7);
    insertFirst(&lista, palavra6);
    insertFirst(&lista, palavra5);
    insertFirst(&lista, palavra4);
    insertFirst(&lista, palavra3);
    insertFirst(&lista, palavra2);
    insertFirst(&lista, palavra1);

    aux = roletaRomana(&lista);

    printf("\nSoldado sorteado = %s", aux->nome);

return 0;
}
