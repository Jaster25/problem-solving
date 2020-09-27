#include<stdio.h>
#include<stdlib.h>
#define MAX 26
typedef enum{false, true} bool;

int map[MAX][MAX];
bool visited[MAX][MAX];
int size;

int houseCount;
int danziCount;
int danzi[MAX];

void dfs(int x, int y) {
	
	int vectX[4] = {0,0,-1,1};
	int vectY[4] = {-1,1,0,0};
		
	for(int i=0 ; i<4 ; ++i) {
		
		int nextX = x + vectX[i];
		int nextY = y + vectY[i];
		
		if(nextX >= 1 && nextX <= size && nextY >= 1 && nextY <= size) {
			if(map[nextX][nextY] == 1 && visited[nextX][nextY] == false) {
			
				visited[nextX][nextY] = true;
				dfs(nextX, nextY);
				
				houseCount++;
			}
		}
	}
}

bool findHouse() {
	
	for(int i=1 ; i<=size ; ++i) {
		for(int j=1 ; j<=size ; ++j) {
			if(map[i][j] == 1 && visited[i][j] == false) {
				
				houseCount = 1;
				visited[i][j] = true;
				dfs(i,j);
				
				danzi[++danziCount] = houseCount;
				return true;
			}
		}
	}
	
	return false;
}

int compare(void* one, void* two) {
	if(*(int*)one > *(int*)two) return 1;
	else if(*(int*)one < *(int*)two) return -1;
	else return 0;	
}

int main() {
	
	scanf("%d", &size);
	
	danziCount = 0;
	
	for(int i=1 ; i<=size ; ++i) {
		for(int j=1 ; j<=size ; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	while( findHouse() ) {}
	
	printf("%d\n", danziCount);
	
	qsort(danzi + 1, danziCount, sizeof(int), compare);
	
	for(int i=1 ; i<=danziCount ; ++i) {
		printf("%d\n", danzi[i]);
	}
}
