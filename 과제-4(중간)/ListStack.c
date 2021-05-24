#include <stdio.h>
#include <stdlib.h>
#include "ListStack.h"

void StackInit(Stack *pstack){
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack){
    if(pstack->head==NULL)
        return TRUE;
    else 
        return FALSE;
}

Data SPop(Stack *pstack){
    Data rdata;
    Node *rnode;

    if(SIsEmpty(pstack)){
        return (char)0;
    }
    rdata = pstack->head->data;
    rnode = pstack->head;
    pstack->head = pstack->head->next;
    free(rnode);
    return rdata;
}

void SPush(Stack *pstack, Data data){
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Data SPeek(Stack *pstack){
    if(SIsEmpty(pstack)){
        return (char)0;
    }
    return pstack->head->data;
}