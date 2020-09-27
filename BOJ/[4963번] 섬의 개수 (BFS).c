#include<stdio.h>
#include<stdlib.h>

typedef enum{false, true} bool;
typedef struct {
	int x, y;
} Point;

int w,h;
int land[51][51];
int visited[51][51];
int count;

Point queue[2500];
int front;
int rear; 

bool isEmpty() {
	if(front == rear) return true;
	else return false;
}

void enqueue(int x, int y) {
	Point temp = {x, y};
	queue[++rear] = temp;
}

Point dequeue() {
	return queue[++front];
}

void reset() {

	count = 0;
	front = 0;
	rear = 0;
	
	for(int i=1 ; i<=50 ; ++i) {
		for(int j=1 ; j<=50 ; ++j) {
			land[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

bool findLand() {
	
	for(int i=1 ; i<=h ; ++i) {
		for(int j=1 ; j<=w ; ++j) {
			
			if(land[i][j] == 1 && visited[i][j] == 0) {

				visited[i][j] = 1;
				enqueue(i,j);
				
				return true;
			}
		}
	}
	
	return false;
}

void bfs() {
	
	while( !isEmpty() ) {
		
		Point now = dequeue();
		
		int vectX[8] = {0, 0, 1, -1, -1, 1, -1, 1};
		int vectY[8] = {1, -1, 0, 0, -1, 1, 1, -1};
		
		for(int i=0 ; i<8 ; ++i) {
			int nextX = now.x + vectX[i];
			int nextY = now.y + vectY[i];
			
			if(nextX >= 1 && nextX <= h && nextY >= 1 && nextY <= w) {
				if(land[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
					visited[nextX][nextY] = 1;
					enqueue(nextX, nextY);
				}
			}
		}
	}
	
	count++;
}

int main() {
	
	scanf("%d%d", &w, &h);
	while(w != 0 && h != 0) {
		
		reset();
		
		//w가 열 h가 행 
		for(int i=1 ; i<=h ; ++i) {
			for(int j=1 ; j<=w ; ++j) {
				scanf("%d", &land[i][j]);
			}
		}

		while( findLand() ) {
			bfs();
		}
		
		printf("%d\n", count);
		scanf("%d%d", &w, &h);
	}
}
