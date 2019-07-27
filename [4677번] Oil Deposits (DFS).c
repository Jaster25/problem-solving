#include<string.h>
typedef struct {
	int x;
	int y;
} point;

int M,N;
int areaNumber = 0;
int pocketNumber = 0;
char map[101][101];
int visited[101][101] = {0, };
int pocketCount[101] = {0, };


void setting() {

	pocketNumber = 0;
	for(int i=0 ; i<=100 ; i++) {
		for(int j=0 ; j<=100 ; j++) {
			map[i][j] = '*';
			visited[i][j] = 0;
		}
	}
}

void go(int x, int y) {
	
	int vectX[8] = {0, 0, -1, -1, -1, 1, 1, 1};
	int vectY[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
	
	for(int i=0 ; i<8 ; ++i) {
		
		int nextX = x + vectX[i];
		int nextY = y + vectY[i];
		
		if(map[nextX][nextY] == '@' && visited[nextX][nextY] == 0) {
			
			visited[nextX][nextY] = 1;
			go(nextX, nextY);
		}
	}
}

point findOil() {
	
	point temp;
	temp.x = -1;
	temp.y = -1;
	
	for(int i=1 ; i<=M ; ++i)
		for(int j=1 ; j<=N ; ++j)
			if(map[i][j]=='@' && visited[i][j]==0) {
				temp.x = i;
				temp.y = j;
				return temp;
			}
	
	return temp;
}

int main() {
	
	scanf("%d%d", &M, &N);
	
	while(M != 0 || N != 0) {
		
		setting();
		areaNumber++;
		
		for(int i=1 ; i<=M ; ++i)
			scanf("%s", map[i]);
		
		
		while(findOil().x != -1 && findOil().y != -1) {
			pocketNumber++;
			
			int nextX = findOil().x;
			int nextY = findOil().y;
			
			visited[nextX][nextY] = 1;
			go(nextX, nextY);
		}
		
		pocketCount[areaNumber-1] = pocketNumber;
		scanf("%d%d", &M, &N);
	}
	
	for(int i=0 ; i<areaNumber ; ++i)
		printf("%d\n", pocketCount[i]);
	
}
