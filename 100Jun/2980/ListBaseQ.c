#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQ.h"

void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data,Data cycle) { //수정
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	newNode->cycle = cycle;

	if (QIsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}
Data Dequeue(Queue* pq) {
	Node* delNode;
	Data retData;

	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}
Data QPeek(Queue* pq) { //수정

	if (QIsEmpty(pq)) {
		return FALSE;
	}
	return pq->front->data;
}