#include<iostream>
#include<utility>
#include<queue>
#define MAX 9
using namespace std;

int N,M;
int map[MAX][MAX];
int testMap[MAX][MAX];
int virusMap[MAX][MAX];

queue<pair<int, int> > q;

int maxSafeZone;

void copyMap() {
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j)
			testMap[i][j] = map[i][j];
}

void virusMapcopy() {
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j)
			virusMap[i][j] = testMap[i][j];
	
}

void bfs() {
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();		
		
		int dY[4] = {0,0,-1,1};
		int dX[4] = {-1,1,0,0};
		
		for(int i=0 ; i<4 ; ++i) {
			int nY = y + dY[i];
			int nX = x + dX[i];
			
			if(nY >= 1 && nY <= N && nX >= 1 && nX <= M) {
				if(virusMap[nY][nX] == 0) {
					q.push(pair<int,int>(nY, nX));
					virusMap[nY][nX] = 2;	
				}
			}
		}
	}
}

void virusSpread() {
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M ; ++j)
			if(virusMap[i][j] == 2) q.push(pair<int,int>(i,j));
			
	bfs();
}

int checkSafezone() {
	int safeZone = 0;
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M ; ++j)
			if(virusMap[i][j] == 0) safeZone++;
			
	return safeZone;
}

void makeWall(int num) {
	
	if(num == 3) {
		virusMapcopy();
		virusSpread();
		int csz = checkSafezone();
		
		if(csz > maxSafeZone) maxSafeZone = csz;
		return;
	}	
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			if(testMap[i][j] == 0) {
				
				testMap[i][j] = 1;
				
				makeWall(num + 1);
				
				testMap[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	
	for(int i = 1; i <= N; ++i)
		for(int j = 1; j <= M; ++j)
			scanf("%d", &map[i][j]);
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ;++j) {
			if(map[i][j] == 0) {
				copyMap();
				//벽으로 가정 
				testMap[i][j] = 1;
				
				makeWall(1);
				
				//다시 복구 
				testMap[i][j] = 0;
			}
		}
	}
	
	printf("%d", maxSafeZone);
}

