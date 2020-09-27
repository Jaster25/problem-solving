#include<iostream>
#include<string.h>
using namespace std;

// R : 1, G : -1, B : 0
int N;
char color;
int MAP[101][101];
bool visited[101][101];

int normalAearCount;
int abnormalAearCount;

int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,1,-1};

void normalBFS(int y, int x) {
	
	visited[y][x] = true;
	
	for(int n=0 ; n<4 ; ++n) {
		
		int nextY = dirY[n] + y;
		int nextX = dirX[n] + x;
		
		if(nextY > 0 && nextY <= N && nextX > 0 && nextX <= N)
			if(!visited[nextY][nextX])
				if(MAP[y][x] == MAP[nextY][nextX])
					normalBFS(nextY,nextX);
	}
}

void abnormalBFS(int y, int x) {
	
	visited[y][x] = true;
	
	for(int n=0 ; n<4 ; ++n) {
		
		int nextY = dirY[n] + y;
		int nextX = dirX[n] + x;
		
		if(nextY > 0 && nextY <= N && nextX > 0 && nextX <= N)
			if(!visited[nextY][nextX]) {
				if(MAP[y][x] == MAP[nextY][nextX])
					abnormalBFS(nextY,nextX);
				else if(MAP[y][x] == (-1) * MAP[nextY][nextX])
					abnormalBFS(nextY,nextX);
			}
	}
}

int main() {
	
	scanf("%d", &N);
		getchar();
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			scanf("%1c", &color);
			if(color == 'R')
				MAP[i][j] = 1;
			else if(color == 'G')
				MAP[i][j] = -1;
			else
				MAP[i][j] = 0;
		}
		getchar();
	}
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=N ; ++j)
			if(!visited[i][j]) {
				normalAearCount++;
				normalBFS(i,j);
			}
	
	memset(visited, false, sizeof(visited));
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=N ; ++j)
			if(!visited[i][j]) {
				abnormalAearCount++;
				abnormalBFS(i,j);
			}
	
	printf("%d %d", normalAearCount, abnormalAearCount);
}
