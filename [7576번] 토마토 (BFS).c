#include<stdio.h>

typedef enum {false, true} bool;
typedef struct {
	int x;
	int y;	
} position;

void enqueue(int x, int y);
position dequeue();
bool isEmpty();
void bfs();

bool allRipen();
int minDay();

position queue[1000000];
int front = 0;
int rear = 0;

int N,M;
tomato[1001][1001] = {0, };
//날짜 기록 
visited[1001][1001] = {0, };

//방향
int vectX[4] = {-1, 1, 0, 0};
int vectY[4] = {0, 0, -1, 1};


int main() {
	
	scanf("%d%d", &M, &N);
	
	for(int i=1 ; i<=N ; i++) {
		for(int j=1;  j<=M ; j++) {
			scanf("%d", &tomato[i][j]);
			
			if(tomato[i][j] == 1) {
				enqueue(i,j);
				visited[i][j] = 1;
			}
		}
	}

	bfs();
	
	if(allRipen()) {
		printf("%d", minDay());
	}
	else {
		printf("-1");
	}
	
}



void enqueue(int x, int y) {
	position temp;
	temp.x = x;
	temp.y = y;
	
	queue[++rear] = temp;
}


position dequeue() {
	
	return queue[++front];	
}


bool isEmpty() {
	if(front == rear) return true;
	else return false;
}


void bfs() {
	
	while( !isEmpty() ) {
		
		position now = dequeue();		
		
		for(int i=0 ; i<4 ; i++) {
			
			int nextX = now.x + vectX[i];
			int nextY = now.y + vectY[i];
			
			if(nextX > 0 && nextX <= N && nextY > 0 && nextY <= M) {
				
				if(tomato[nextX][nextY] == 0) {
					
					if(visited[nextX][nextY] == 0) {
						
						enqueue(nextX, nextY);
						tomato[nextX][nextY] = 1;
						visited[nextX][nextY] = visited[now.x][now.y] + 1;
						
					}
				}
			}
		}
	}
}

bool allRipen() {
	
	for(int i=1 ; i<=N ; i++)
		for(int j=1;  j<=M ; j++)
			if(tomato[i][j] == 0 && visited[i][j] == 0)
				return false;
	
	
	
	return true;
}

int minDay() {
	
	int num = 0;
	
	for(int i=1 ; i<=N ; i++)
		for(int j=1;  j<=M ; j++)
			if(visited[i][j] > num) num = visited[i][j];
	
	if(num > 0)	return num - 1;
	else return 0;
}

