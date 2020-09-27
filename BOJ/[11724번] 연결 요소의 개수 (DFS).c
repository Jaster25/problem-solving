#include<stdio.h>
#define MAX 1001
typedef enum{false, true} boolean;

int N, M;
int count;
int matrix[MAX][MAX];
boolean visited[MAX];

void dfs(int x) {
	
	visited[x] = true;
	
	for(int i=1 ; i<=N ; ++i) {
		if(matrix[x][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}

int main() {
	
	count = 0;
	scanf("%d%d", &N, &M);
	
	for(int i=0 ; i<M ; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	
	for(int i=1 ; i<=N ; ++i) visited[i] = false;
	
	for(int i=1 ; i<=N ; ++i) {
		if(visited[i] == false) {
			dfs(i);
			count++;
		}
	}
	
	printf("%d", count);	
}
