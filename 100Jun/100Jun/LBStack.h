#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE          1
#define FALSE         0

typedef int sData;

typedef struct _snode {
	sData data;
	struct _snode* next;
} sNode;

typedef struct _listStack {
	sNode* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, sData data);
sData SPop(Stack* pstack);
sData SPeek(Stack* pstack);

#endif