#include<stdio.h>
#define MAX 100001

int N, K;

int visitedTime[MAX];
int queue[MAX];
int front;
int rear;

void enqueue(int a) {
	queue[++rear] = a;
}

int dequeue() {
	return queue[++front];
}

int bfs() {
	
	//초기값은 1로 설정
	enqueue(N);
	visitedTime[N] = 1;
	
	while(front != rear) {
		
		int now = dequeue();
		if(now == K) return visitedTime[now];
		
		
		//범위 조심 
		if(now + 1 <= MAX && visitedTime[now + 1] == 0) {
			enqueue(now + 1);
			visitedTime[now + 1] = visitedTime[now] + 1;
		}
		
		if(now - 1 >= 0 && visitedTime[now - 1] == 0) {
			enqueue(now - 1);
			visitedTime[now - 1] = visitedTime[now] + 1;
		}
	
		if(now * 2 <= MAX && visitedTime[now * 2] == 0) {
			enqueue(now * 2);
			visitedTime[now * 2] = visitedTime[now] + 1;
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &K);
	
	//초기값을 0이 아닌 1로 하여 마지막에 다시 1 빼주기 
	printf("%d", bfs() - 1);
}
