#include<stdio.h>
#define MAX 51
typedef enum{false, true} bool;

int N, M, K;
int map[MAX][MAX];
bool visited[MAX][MAX];
int earthWarm;

void reset() {

	earthWarm = 0;
	for(int i=1 ; i<=MAX ; ++i) {
		for(int j=1 ; j<=MAX ; ++j) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void dfs(int y, int x) {
	
	int vectX[4] = {0,0,-1,1};
	int vectY[4] = {-1,1,0,0};
	
	for(int i=0 ; i<4 ; ++i) {
		int nextY = y + vectY[i];
		int nextX = x + vectX[i];
		
		if(nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M) {
			if(map[nextY][nextX] == 1 && visited[nextY][nextX] == false) {
				
				visited[nextY][nextX] = true;
				dfs(nextY, nextX);
			}
		}
	}
}

bool findCabbage() {
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			if(map[i][j] == 1 && visited[i][j] == false) {
				
				visited[i][j] = true;
				dfs(i,j);
				earthWarm++;
				
				return true;
			}
		}
	}
	
	return false;
}

int main() {
	
	int testCase;
	scanf("%d", &testCase);
	
	for(int i=0 ; i<testCase ; ++i) {
		
		reset();
		scanf("%d%d%d", &M, &N, &K);
		
		for(int j=0 ; j<K ; ++j) {
			
			int x,y;
			scanf("%d%d", &x, &y);
			map[y+1][x+1] = 1;
		}
		
		while( findCabbage() ) {}
		
		printf("%d\n", earthWarm);
	}
}
