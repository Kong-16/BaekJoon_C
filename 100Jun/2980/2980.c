//Ʈ���� ����� ���ϰ� �ͼ� ����ð��� ���� ������ ������.. ���ε� ��� �� �� �� ����...

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQ.h"

/*
typedef struct _vehicle {
	int pos;
}Vehicle;

void go(Vehicle* t) {
	t->pos++;
}

typedef struct _trafficlight {
	int pos;
	int redtime;
	int cycle;
}TrafficLight;

void TLInit(TrafficLight* t, int p, int rtime, int rtPgt) {
	t->pos = p;
	t->redtime = rtime;
	t->cycle = rtPgt;
}

int IsRed(TrafficLight* t, int time) {
	if (time % t->cycle < t->redtime - 1)
		return RED;
	else
		return GREEN;
}
int main() {
	int i, time, lightNum, roadLen, lp, rt, gt;
	int vehiPos = 0;
	scanf("%d %d ", &lightNum, &roadLen);

	TrafficLight* tl = (TrafficLight*)malloc(sizeof(TrafficLight) * lightNum);

	for (i = 0; i < lightNum; i++) {
		scanf("%d %d %d", &lp, &rt, &gt);
		TLInit(tl + i, lp, rt, gt);
	}
*/

int ForGreen(Queue* pq, int time) {
	int nowtime = time % pq->front->cycle;
	int greentime = pq->front->redtime;
	if (nowtime >= greentime) // �ʷϺ� �϶�
		return 0;
	else
		return greentime - nowtime;
}
int main(){
	int i, lightNum, roadLen, lp, rt, gt, ptime;
	int time = 0;
	int vehiPos = 0;
	Queue tlq, pq;
	QueueInit(&tlq); // ������, ����Ŭ �����ϴ� ��ȣ��
	QueueInit(&pq); //pq�� ��ȣ�� ��ġ�� ����

	scanf("%d %d ", &lightNum, &roadLen);
	
	for (i = 0; i < lightNum; i++) {
		scanf("%d %d %d", &lp, &rt, &gt);
		Enqueue(&pq, lp, 0); //redtime == ��ġ. cycle�� �ʿ�����Ƿ� 0����.
		Enqueue(&tlq, rt, rt + gt);
	}

	while (vehiPos != roadLen) { //�� ��ġ�� ���� ���̸�ŭ �� ������
		if (vehiPos == QPeek(&pq)) { //���� ��ȣ�� ��ġ���� ����
			ptime = ForGreen(&tlq, time);
			if (ptime)
				time = time + ptime;
			Dequeue(&pq);
			Dequeue(&tlq);
		}
		time++;    //��ȣ�� ������ 1�ʿ� ��ĭ ����.
		vehiPos++;
	}

	printf("%d",time);
	return 0;
}