#include<stdio.h>
#include<math.h>
#define MIN(a,b) (a<b ? a : b)
#define MAX 101

typedef enum{false, true} bool;
typedef struct {
	int y,x;
} Point;

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];

int islandCount;

Point queue[MAX * MAX];
int front;
int rear;

void reset() {
	front = 0;
	rear = 0;
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			visited[i][j] = false;
		}
	}
}

void enqueue(int y, int x) {
	Point temp = {y, x};
	queue[++rear] = temp;
}

Point dequeue() {
	return queue[++front];
}

bool isEmpty() {
	return (front == rear);
}

//map의 요소들을 섬 번호로 변환 islandCount
void landNumBFS() {
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			if(map[i][j] != 0 && visited[i][j] == false) {

				islandCount++;
				enqueue(i,j);
				map[i][j] = islandCount;
				visited[i][j] = true;
				
				while( !isEmpty() ) {
					Point now = dequeue();
					int nowY = now.y;
					int nowX = now.x;
					
					int vectY[4] = {0,0,-1,1};
					int vectX[4] = {-1,1,0,0};
					
					for(int i=0 ; i<4 ; ++i) {
						int nextY = nowY + vectY[i];
						int nextX = nowX + vectX[i];
						
						if(nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= N) {
							if(map[nextY][nextX] != 0 && visited[nextY][nextX] == false) {
								map[nextY][nextX] = islandCount;
								visited[nextY][nextX] = true;
								enqueue(nextY, nextX);
							}
						}
					}
				}
			}
		}
	}
}

int findLandBFS(int y, int x) {
	
	int islandNum = map[y][x];
	int path;	
	enqueue(y,x);
	
	while( !isEmpty() ) {
		Point now = dequeue();
		int nowY = now.y;
		int nowX = now.x;
		
		int dY[4] = {0,0,-1,1};
		int dX[4] = {-1,1,0,0};

		for(int i=0 ; i<4 ; ++i) {
			int nextY = nowY + dY[i];
			int nextX = nowX + dX[i];
			
			if(nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= N && map[nextY][nextX] != islandNum) {
				//다른 섬을 만난 경우 
				if(map[nextY][nextX] != 0) {
					path = abs(y - nextY) + abs(x - nextX) - 1;
					return path;
				}
				//아직 바다를 탐색 
				else if(map[nextY][nextX] == 0 && visited[nextY][nextX] == false) {
					enqueue(nextY, nextX);
					visited[nextY][nextX] = true;
				}
			}
		}
	}
	
	return MAX * MAX;
}

int main() {
	int pathMinimum = MAX * MAX;
	int path;
	
	scanf("%d", &N);
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	
	//섬 번호로 바꿈
	islandCount = 0;
	landNumBFS();
	
	//섬 테두리에서 시작 
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			if(map[i][j] != 0) {
				reset();
					
				int dY[4] = {0,0,-1,1};
				int dX[4] = {-1,1,0,0};
		
				for(int k=0 ; k<4 ; ++k) {
					int nextY = i + dY[k];
					int nextX = j + dX[k];
					
					if(map[nextY][nextX] == 0) {
						path = findLandBFS(i,j);
						pathMinimum = MIN(path, pathMinimum);
					}
				}
			}
		}
	}
	
	printf("%d", pathMinimum);
}
