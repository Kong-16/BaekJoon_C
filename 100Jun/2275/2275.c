#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LBS.h"

#define MAX_LEN          100

int main() {
	char str[MAX_LEN],tok;
	int i, instack,sum;
	Stack stack;
	StackInit(&stack);
	
	scanf("%s", str);

	switch (str[0]){
	case 'H':
		SPush(&stack, 1);
		break;
	case 'C':
		SPush(&stack, 12);
		break;
	case 'O':
		SPush(&stack, 16);
		break;
	}

	sum = 0;
	for (i = 1; i < strlen(str); i++) {
		tok = str[i];

		if (isdigit(tok)) {
			instack = SPop(&stack);
			SPush(&stack, instack * atoi(&tok)); //- '0' ���� atoi�� ���ƺ�.
		}
		else {
			switch (tok) {
			case 'H':
				SPush(&stack, 1);
				break;
			case 'C':
				SPush(&stack, 12);
				break;
			case 'O':
				SPush(&stack, 16);
				break;
			case '(':
				SPush(&stack, tok);
				break;
			case ')': // )�� ���ð�� ( ���� �� ���� ���þ��� �� ����.
				instack = SPop(&stack);
				while (instack != '(') {
					sum = sum + instack;
					instack = SPop(&stack);
				}
				SPush(&stack, sum); //stack�� sum �� �ְ� sum �ʱ�ȭ.
				sum = 0;
				break;
			}
		}
	}

	sum = 0;
	while (!SIsEmpty(&stack)) {
		instack = SPop(&stack);
		sum = sum + instack;
	}

	printf("%d", sum);
	return 0;
}