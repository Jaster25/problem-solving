#include<stdio.h>

typedef enum{false, true} bool;
typedef struct {
	int x;	
	int y;
} position;

int N;
int danziNumber = 0;
int map[260][260] = {0, };
int visited[260][260] = {0, };
int danziMap[260][260] = {0, };
int count[1000000] = {0, };

position queue[1000000];
int front = 0;
int rear = 0;

void enqueue(int x, int y);
position dequeue();
bool isEmpty();
position findHouse();
void bfs();
void quickSort(int *array, int start, int end);

int main() {
	
	scanf("%d", &N);
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=N ; j++)
			scanf("%1d", &map[i][j]);
	
	while(findHouse().x != -1 && findHouse().y != -1) {
		
		enqueue(findHouse().x, findHouse().y);
		bfs();
	}
	
	quickSort(count, 1, danziNumber);
	
	printf("%d\n", danziNumber);
	for(int i=1 ; i<=danziNumber ; i++)
		printf("%d\n", count[i]);
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

position findHouse() {
	
	position temp;
	temp.x = -1;
	temp.y = -1;
	
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=N ; j++)
			if(map[i][j]==1 && visited[i][j]==0) {
				temp.x = i;
				temp.y = j;
				
				return temp;
			}
			
	return temp;
}

void bfs() {
	
	danziNumber++;
	
	while( !isEmpty() ) {
		
		position now = dequeue();
			
		int vectX[4] = {-1, 1, 0, 0};
		int vectY[4] = {0, 0, -1, 1};
		
		for(int i=0 ; i<4 ; i++) {
			
			int nextX = now.x + vectX[i];
			int nextY = now.y + vectY[i];
			
			if(nextX >= 1 && nextX <=25 && nextY >= 1 && nextY <=25) {
				if(map[nextX][nextY] == 1) {
					if(visited[nextX][nextY] == 0) {
						
						enqueue(nextX, nextY);
						visited[nextX][nextY] = 1;
						danziMap[nextX][nextY] = danziNumber;
						count[danziNumber]++;
					}
				}
			}
		}
	}
}

void quickSort(int *array, int start, int end) {
	
	if(start >= end) return;
	
	int pivot = array[start];
	int toRight = start + 1;
	int toLeft = end;
	
	while(toRight <= toLeft) {
		
		while(array[toRight] <= pivot && toRight <= end) { 
			toRight++;
		}
		
		while(array[toLeft] >= pivot && toLeft > start) {
			toLeft--;
		}
		
		
		if(toRight > toLeft) {
			int temp = array[start];	
			array[start] = array[toLeft];
			array[toLeft] = temp;
		}
		
		else {
			int temp = array[toLeft];	
			array[toLeft] = array[toRight];
			array[toRight] = temp;
		}
		
	}
	
	quickSort(array, start, toLeft-1);
	quickSort(array, toLeft+1, end);
} 
