#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLL7348.h"

int main() {
	List list;
	int start, end, i ,n;

	ListInit(&list);

	scanf("%d", &n);

	scanf("%d %d", &start, &end);
	if (start % 2 == 0)
		start = start - 1;
	if (end % 2 == 1)
		end = end + 1;
	LNextInsert(&list, start, end); // 처음은 검사안하고 넣음

	for (i = 1; i < n; i++) {
		LFirst(&list);
		scanf("%d %d", &start, &end);
		if (start % 2 == 0) // 아랫방 시작일경우 윗방도 못쓰기때문에 -1
			start = start - 1;
		if (end % 2 == 1) //마찬가지
			end = end + 1;
		if (TRUE) {
			while (IsOverlap(&list, start, end)) { //겹치면 다음리스트 참조
				if (!LNext(&list)) { //끝까지 겹치면 옆으로 리스트 생성
					LNextInsert(&list, start, end);
					break;
				}
			}
		}
		else
			LDownInsert(&list, start, end); //안겹치면 거기서 아래 리스트 생성.
	}

	printf("%d", LCount(&list) * 10);


	return 0;
}