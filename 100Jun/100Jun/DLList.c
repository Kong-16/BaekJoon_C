#include <stdlib.h>
#include <stdio.h>
#include "DLList.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->prev = plist->head;
	plist->tail->next = NULL;

	plist->numOfData = 0;
}

void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->subdata = NULL;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List* plist, Data* pdata) {
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist) {
	Node* rpos = plist->cur;
	Data remv = rpos->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;

	free(rpos);
	(plist->numOfData)--;
	return remv;
}

int LPrevious(List* plist, Data* pdata) { //수정함.
	if (plist->cur->prev->subdata != NULL) //이전 값이 있으면
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

int LCount(List* plist) {
	return plist->numOfData;
}

//추가
void LPush(List* plist, SubData data) { 
	plist->cur->subdata = data;
}

Node* LGetCur(List* plist) {
	return plist->cur;
}

void LSetCur(List* plist, Node *pnode) {
	plist->cur = pnode;
}