#include<stdio.h>
#include<stdlib.h>
typedef enum{false, true} bool;

int matrix[1001][1001] = {0,};
int visited[1001] = {0,};

int N,M;
int count;

int queue[1001];
int front;
int rear;

void enqueue(int y) {
	queue[++rear] = y;
}

int dequeue() {
	return queue[++front];
}


bool isEmpty() {
	if(front == rear) return true;
	else return false;
}

void bfs() {
	
	while( !isEmpty() ) {
		
		int nowX = dequeue();
		
		for(int i = 1 ; i<=N ; ++i) {
			if(matrix[nowX][i] == 1 && visited[i] == 0) {
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
}

bool findComponent() {
	
	int check = 0;
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			if(visited[i] == 0) {
				if(matrix[i][j] == 1) {
					enqueue(i);
					
					visited[i] = 1;
					check = 1;
				}
			}
		}
		if(check == 1) return true;
	}
	
	return false;
}

int main() {

	front = 0;
	rear = 0;
	
	scanf("%d%d", &N, &M);
	
	for(int i=0 ; i<M ; ++i) {
		int u,v;
		scanf("%d%d", &u, &v);
		
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	
	count = 0;
	while( findComponent() ) {
		bfs();
		count++;
	}
	
	//혼자있는 정점인 경우
	for(int i=1 ; i<=N ; ++i) if(visited[i] == 0) count++;
	
	printf("%d", count);
}
