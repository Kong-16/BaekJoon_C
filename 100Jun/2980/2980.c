//트리때 멘붕이 심하게 와서 실행시간에 대한 집착이 심해짐.. 본인도 어떻게 할 수 가 없음...

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
	if (nowtime >= greentime) // 초록불 일때
		return 0;
	else
		return greentime - nowtime;
}
int main(){
	int i, lightNum, roadLen, lp, rt, gt, ptime;
	int time = 0;
	int vehiPos = 0;
	Queue tlq, pq;
	QueueInit(&tlq); // 빨간불, 사이클 저장하는 신호등
	QueueInit(&pq); //pq는 신호등 위치만 저장

	scanf("%d %d ", &lightNum, &roadLen);
	
	for (i = 0; i < lightNum; i++) {
		scanf("%d %d %d", &lp, &rt, &gt);
		Enqueue(&pq, lp, 0); //redtime == 위치. cycle값 필요없으므로 0넣음.
		Enqueue(&tlq, rt, rt + gt);
	}

	while (vehiPos != roadLen) { //차 위치가 도로 길이만큼 올 때까지
		if (vehiPos == QPeek(&pq)) { //차가 신호등 위치까지 오면
			ptime = ForGreen(&tlq, time);
			if (ptime)
				time = time + ptime;
			Dequeue(&pq);
			Dequeue(&tlq);
		}
		time++;    //신호등 없으면 1초에 한칸 전진.
		vehiPos++;
	}

	printf("%d",time);
	return 0;
}