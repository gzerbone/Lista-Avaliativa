#include "node.h"
#include <stddef.h>
NODE *createNode()
{
    NODE *ptrNode;

    ptrNode = (NODE *) malloc(sizeof(NODE));
    ptrNode->next = NULL;

    return ptrNode;
}
void freeNode(NODE *ptrNode)
{
    free(ptrNode);
}
