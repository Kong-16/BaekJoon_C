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
	LNextInsert(&list, start, end); // ó���� �˻���ϰ� ����

	for (i = 1; i < n; i++) {
		LFirst(&list);
		scanf("%d %d", &start, &end);
		if (start % 2 == 0) // �Ʒ��� �����ϰ�� ���浵 �����⶧���� -1
			start = start - 1;
		if (end % 2 == 1) //��������
			end = end + 1;
		if (TRUE) {
			while (IsOverlap(&list, start, end)) { //��ġ�� ��������Ʈ ����
				if (!LNext(&list)) { //������ ��ġ�� ������ ����Ʈ ����
					LNextInsert(&list, start, end);
					break;
				}
			}
		}
		else
			LDownInsert(&list, start, end); //�Ȱ�ġ�� �ű⼭ �Ʒ� ����Ʈ ����.
	}

	printf("%d", LCount(&list) * 10);


	return 0;
}