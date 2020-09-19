#include "LBStack.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, sData data) {
	sNode* newNode = (sNode*)malloc(sizeof(sNode));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

sData SPop(Stack* pstack) {
	sData rdata;
	sNode* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

sData SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->head->data;
}