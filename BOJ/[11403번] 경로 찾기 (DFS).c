#include<stdio.h>
#define MAX 101
typedef enum{false, true} bool;

int vertex;
int matrix[MAX][MAX];
int posible[MAX][MAX];
bool visited[MAX];

void reset() {

	for(int i=1 ; i<=vertex ; ++i) {
		visited[i] = false;
	}
}

void dfs(int y) {
	
	for(int i=1 ; i<=vertex ; ++i) {
		if(matrix[y][i] == 1 && visited[i] == false) {

			visited[i] = true;
			dfs(i);
		}
	}
}

int main() {
	
	scanf("%d", &vertex);
	
	for(int i=1 ; i<=vertex ; ++i) {
		for(int j=1 ; j<=vertex ; ++j) {
			scanf("%d", &matrix[i][j]);
		}

		visited[i] = false;
	}
	
	for(int i=1 ; i<=vertex ; ++i) {
		for(int j=1 ; j<=vertex ; ++j) {

			reset();
			dfs(i);
			
			//중요!! 시작 행을 visited 처리 하면 안됨 방향성이 있는 그래프이기 때문
			
			if(visited[j] == true) posible[i][j] = 1;
			else posible[i][j] = 0;
		}
	}
	
	for(int i=1 ; i<=vertex ; ++i) {
		for(int j=1 ; j<=vertex ; ++j) {
			printf("%d ", posible[i][j]);
		}
		printf("\n");
	}
}
