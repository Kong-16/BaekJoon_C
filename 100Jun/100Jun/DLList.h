#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE            1
#define FALSE           0

typedef char Data;
typedef int SubData;

typedef struct _node {
	Data data;
	SubData subdata;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _DLinkedList {
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;

} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, Data data);


int LFirst(List* plist, Data* pdata);
int LNext(List* plist, Data* pdata);
Data LRemove(List* plist);
int LPrevious(List* plist, Data* pdata);
int LCount(List* plist);

//Ãß°¡
void LPush(List* plist, SubData data); 
Node* LGetCur(List* plist);
void LSetCur(List* plist, Node* pnode);
#endif