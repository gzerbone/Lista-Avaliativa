#include "node.h"
#include <stdio.h>
#include <stdlib.h>

NODE* createNode(){
    NODE* p;

    p = (NODE*) malloc(sizeof(NODE));
    p->next = NULL;
    p->previous = NULL;

    return p;
}
void freeNode(NODE* p){
    free(p);
}
