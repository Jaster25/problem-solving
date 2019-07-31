#include<stdio.h>
#include<string.h>

typedef struct {
	int x;
	int y;
} point;

int M,N;
int pocketNumber = 0;
char map[102][102];
int visited[102][102];

void setting() {
	pocketNumber = 0;
	for(int i=0 ; i<M ; i++)
		for(int j=0 ; j<N ; j++)
			visited[i][j] = 0;
}

void go(int x, int y) {
	
	int vectX[8] = {0, 0, -1, -1, -1, 1, 1, 1};
	int vectY[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
	
	for(int i=0 ; i<8 ; ++i) {
		
		int nextX = x + vectX[i];
		int nextY = y + vectY[i];
		
		if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
			if(map[nextX][nextY] == '@' && visited[nextX][nextY] == 0) {
				visited[nextX][nextY] = 1;
				go(nextX, nextY);
			}
		}
	}
}

point findOil() {
	
	point temp;
	temp.x = -1;
	temp.y = -1;
	
	for(int i=0 ; i<M ; ++i) {
		for(int j=0 ; j<N ; ++j) {
			if(map[i][j]=='@' && visited[i][j]==0) {
				temp.x = i;
				temp.y = j;
				return temp;
			}
		}
	}
	
	return temp;
}

int main() {
	
	scanf("%d%d", &M, &N);
	while(M != 0 && N != 0) {
		
		setting();
		
		for(int i=0 ; i<M ; ++i)
			scanf("%s", map[i]);
		
		while(findOil().x != -1 && findOil().y != -1) {
			pocketNumber++;
			
			int nX = findOil().x;
			int nY = findOil().y;
			
			visited[nX][nY] = 1;
			go(nX, nY);
		}
		
		printf("%d\n", pocketNumber);
		scanf("%d%d", &M, &N);
	}
}
