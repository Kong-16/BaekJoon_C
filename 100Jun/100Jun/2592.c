#define _CRT_SECURE_NO_WARNINGS

#include "DLList.h"
#include "LBStack.h"
#include <stdio.h>
#include <stdlib.h>

/*
void LPush(List* plist, SubData data) {
	plist->cur->subdata = data;              �̰� �ȵ� ��? -> list�� ���� stack�� ��� �̸��� ���Ƽ� �����߻�.
}*/

int main() {
	Stack stack;
	List list;
	Node* tmp;
	int i, num;
	char ch,data;

	StackInit(&stack);
	ListInit(&list);
	for (i = 0; i < 10; i++) { //0 ���� 9���� ���ÿ� ����.
		SPush(&stack, i);
	}

	scanf("%d", &num);
	
	for (i = 0; i < num; i++) {
		scanf(" %c", &ch);
		LInsert(&list, ch); //�ε�ȣ ����Ʈ�� ����.
	}     
	LInsert(&list, '>');
	
	LFirst(&list, &data);
	do {
		if (data == '>') {
			tmp = LGetCur(&list); //cur �� ����
			do {
				LPush(&list, SPop(&stack));
			} while (LPrevious(&list, &data));
			if (tmp->next == NULL)
				break;
			LSetCur(&list, tmp);
		} //cur�� �ǵ帮�� ���� LNext, Previous�� ������. ��? ���ܻ����� NULL�� ����ų���� �ƴ� tail�� ����ų���� �س����Ƿ�
	} while (LNext(&list,&data)); //->cur2 ����. �ذ�!

	LFirst(&list, &data);
	do {
		printf("%d", LGetCur(&list)->subdata);
	} while (LNext(&list, &data));
	

	return 0;
}