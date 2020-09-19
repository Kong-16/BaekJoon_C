#include "LBS.h"
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

void SPush(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;
	printf("%d»ðÀÔ ", data);
	pstack->head = newNode;
}
Data SPop(Stack* pstack) {
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}
Data SPeek(Stack* pstack) {
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
	}
	return pstack->head->data;
}