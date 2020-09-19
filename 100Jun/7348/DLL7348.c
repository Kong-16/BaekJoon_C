#include <stdlib.h>
#include <stdio.h>
#include "DLL7348.h"

void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->prev = plist->head;
	plist->tail->next = NULL;

	plist->numOfData = 0;
}

void LNextInsert(List* plist, Data start, Data end) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->start = start;
	newNode->end = end;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

void LDownInsert(List* plist, Data start, Data end) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->start = start;
	newNode->end = end;

	newNode->down = NULL;
	plist->downcur->down = newNode;
}

int LFirst(List* plist) {
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	plist->downcur = plist->cur;
	plist->downcur->down = NULL;

	return TRUE;
}
int LNext(List* plist) {
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	plist->downcur = plist->cur;

	return TRUE;
}

int LDown(List* plist) {
	if (plist->downcur->down == NULL)
		return FALSE;

	plist->downcur = plist->downcur->down;
	return TRUE;
}

int LCount(List* plist) {
	return plist->numOfData;
}

int IsOverlap(List* plist, Data start, Data end) {
	Data s, e;
	s = plist->downcur->start;
	e = plist->downcur->end;
	if (start < s || e < start) { //start가 s와 e사이에 없을 때
		if (end < s || e < end) {//end도 없을 때
			if (!LDown(plist))//downcur 한칸 내리고 재귀
				return FALSE;
			return IsOverlap(plist, start, end);
		}
	}
	return TRUE;
}