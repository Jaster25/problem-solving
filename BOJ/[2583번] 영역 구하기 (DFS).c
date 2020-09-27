#include<stdio.h>
#include<stdlib.h>
#define MAX 101
typedef enum{false, true} bool;

int M, N, K;
bool map[MAX][MAX];
bool visited[MAX][MAX];

int territory;
int extent[MAX];

void  dfs(int a, int b) {
	
	int dY[4] = {0,0,-1,1};
	int dX[4] = {-1,1,0,0};
	
	for(int i=0 ; i<4 ; ++i) {
		int nY = a + dY[i];
		int nX = b + dX[i];
		
		if(nY >= 0 && nY < M && nX >= 0 && nX < N) {
			if(map[nY][nX] == false && visited[nY][nX] == false) {
				extent[territory]++;
				visited[nY][nX] = true;
				dfs(nY, nX);
			}
		}
	}
}

int compare(void* a, void* b) {
	return (*(int*)a > *(int*)b) * 2 -1;
}

int main() {
	
	scanf("%d%d%d", &M, &N, &K);
	
	for(int i=0 ; i<K ; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        
		for(int y=y1 ; y<y2 ; y++)
			for (int x=x1 ; x<x2 ; x++)
				map[y][x] = true;
	}
	
	for(int i=0 ; i<M ; ++i) {
			for(int j=0 ; j<N ; ++j) {
				if(visited[i][j] == false && map[i][j] == false) {
					visited[i][j] = true;
					extent[territory]++;
					dfs(i,j);
					territory++;
			}
		}
	}
	
	qsort(extent, territory, sizeof(int), compare);
	
	printf("%d\n", territory);
	for(int i=0 ; i<territory ; ++i) {
		printf("%d ", extent[i]);
	}
}
