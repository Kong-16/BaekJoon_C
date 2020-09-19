#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE            1
#define FALSE           0

typedef int Data;

typedef struct _node {
	Data start;
	Data end;
	struct _node* next;
	struct _node* down;
	struct _node* prev;
} Node;

typedef struct _DLinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	Node* downcur;
	int numOfData;

} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);
void LNextInsert(List* plist, Data start,Data end);
void LDownInsert(List* plist, Data start,Data end);

int LFirst(List* plist);
int LNext(List* plist);
int LDown(List* plist);
int LCount(List* plist);

int IsOverlap(List* plist, Data start, Data end);
#endif