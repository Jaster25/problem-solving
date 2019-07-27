#include<stdio.h>
#include<math.h>
#define MAX 183

typedef enum{false, true} boolean;

typedef struct {
	int x,y;
} point;

int N,M;
int bitmap[MAX][MAX];
int distance[MAX][MAX];
boolean visited[MAX][MAX];

point queue[MAX];
int front;
int rear;

boolean isEmpty() {
	return (front == rear);
}

void enqueue(int x, int y) {
	point temp = {x,y};
	queue[++rear] = temp;
}

point dequeue() {
	return queue[++front];
}

void reset() {
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			visited[i][j] = false;
		}
	}
	front = 0;
	rear = 0;
}

void bfs(int x, int y) {
	
	reset();
	enqueue(x,y);
	visited[x][y] = true;
	
	int vectX[4] = {1, -1, 0, 0};
	int vectY[4] = {0, 0, -1, 1};
	
	while( !isEmpty() ) {
		
		point now = dequeue();
		
		for(int i=0 ; i<4 ; ++i) {
			
			int nextX = now.x + vectX[i];
			int nextY = now.y + vectY[i];
			
			if(nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= M) {
				if(bitmap[nextX][nextY] == 1) {
					distance[x][y] = abs(x - nextX) + abs(y - nextY);
					return;
				}
				
				else if(visited[nextX][nextY] == false) {
					enqueue(nextX, nextY);
					visited[nextX][nextY] = true;
				}
			}
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			scanf("%1d", &bitmap[i][j]);
		}
	}
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			if(bitmap[i][j] == 0) bfs(i,j);
		}
	}

	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			printf("%d ", distance[i][j]);
		}
		printf("\n");
	}
}
