#include<stdio.h>

typedef enum {false, true} bool;

int map[101][101] = {0, };
int visited[101][101] = {0, };
int N, M;

void go(int x, int y) {
	
	int vectX[4] = {0, 0, 1, -1};
	int vectY[4] = {1, -1, 0, 0};
	
	for(int i=0 ; i<4 ; ++i) {
		
		int nextX = x + vectX[i];
		int nextY = y + vectY[i];
		
		if(map[nextX][nextY] == 1 && visited[nextX][nextY] == 0) {
			
			printf("---------------\n");
			for(int i=1 ; i<=N ; i++) {
				for(int j=1; j<=M ; j++) {
					printf("%d ", visited[i][j]);
				}printf("\n");
			}
			
			visited[nextX][nextY] = 1;
			go(nextX, nextY);
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for(int i=1 ; i<=N ; i++)
		for(int j=1 ; j<=M ; j++)
			scanf("%1d", &map[i][j]);
	
	visited[1][1] = 1;
	go(1,1);
	
	printf("---------------\n");
	for(int i=1 ; i<=N ; i++) {
		for(int j=1; j<=M ; j++) {
			printf("%d ", visited[i][j]);
		}printf("\n");
	}
	
	printf("%d", visited[N][M]);
}


/*
4 6
101111
101010
101011
111011


3 4
1111
1001
1101
*/
