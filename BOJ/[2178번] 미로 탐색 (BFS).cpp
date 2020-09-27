#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int N, M;
int maze[MAX][MAX];
int visited[MAX][MAX];

queue<pair<int, int> >q;

void bfs(int a, int b) {
	
	visited[a][b] = 1;
	q.push(make_pair(a,b));
	
	while(!q.empty()) {
		
		pair<int, int> temp = q.front();
		q.pop();
		
		int dY[4] = {0,0,-1,1};
		int dX[4] = {-1,1,0,0};
		
		for(int i=0 ; i<4 ; ++i) {
			int nextY = temp.first + dY[i];
			int nextX = temp.second + dX[i];
			
			if(nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M) {
				if(maze[nextY][nextX] == 1 && visited[nextY][nextX] == 0) {
					visited[nextY][nextX] = visited[temp.first][temp.second] + 1;
					q.push(pair<int, int>(nextY, nextX));
				}
			}
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=M ; ++j)
			scanf("%1d", &maze[i][j]);
	
	bfs(1,1);
	
	printf("%d", visited[N][M]);
}
