#define _CRT_SECURE_NO_WARNINGS

#include "DLList.h"
#include "LBStack.h"
#include <stdio.h>
#include <stdlib.h>

/*
void LPush(List* plist, SubData data) {
	plist->cur->subdata = data;              이거 안됨 왜? -> list의 노드와 stack의 노드 이름이 같아서 오류발생.
}*/

int main() {
	Stack stack;
	List list;
	Node* tmp;
	int i, num;
	char ch,data;

	StackInit(&stack);
	ListInit(&list);
	for (i = 0; i < 10; i++) { //0 부터 9까지 스택에 삽입.
		SPush(&stack, i);
	}

	scanf("%d", &num);
	
	for (i = 0; i < num; i++) {
		scanf(" %c", &ch);
		LInsert(&list, ch); //부등호 리스트에 삽입.
	}     
	LInsert(&list, '>');
	
	LFirst(&list, &data);
	do {
		if (data == '>') {
			tmp = LGetCur(&list); //cur 값 저장
			do {
				LPush(&list, SPop(&stack));
			} while (LPrevious(&list, &data));
			if (tmp->next == NULL)
				break;
			LSetCur(&list, tmp);
		} //cur을 건드리는 순간 LNext, Previous등 오류남. 왜? 예외사항을 NULL을 가리킬때가 아닌 tail을 가리킬때로 해놨으므로
	} while (LNext(&list,&data)); //->cur2 만듬. 해결!

	LFirst(&list, &data);
	do {
		printf("%d", LGetCur(&list)->subdata);
	} while (LNext(&list, &data));
	

	return 0;
}