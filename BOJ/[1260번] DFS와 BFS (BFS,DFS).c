#include<stdio.h>
#define MAX 1001
typedef enum{false, true} boolean;

int N, M, V;
int matrix[MAX][MAX];
boolean visited[MAX];

//BFS Å¥ 
int queue[MAX];
int front;
int rear;

boolean isEmpty() {
	return (front == rear);
}

void enqueue(int x) {
	queue[++rear] = x;
}

int dequeue() {
	return queue[++front];
}

void bfs(int x) {
	
	enqueue(x);
	visited[x] = true;
	
	while( !isEmpty() ) {
		
		int y = dequeue();
		printf("%d ", y);
	
		for(int i=1 ; i<=N ; ++i) {
			if(visited[i] == false && matrix[y][i] == 1) {
				enqueue(i);
				visited[i] = true;
			}
		}
	}
}
//BFS

void reset() {
	for(int i=0 ; i<=N ; ++i) visited[i] = false;
}

//DFS Àç±Í 
void dfs(int x) {
	
	visited[x] = true;
	printf("%d ", x);
	
	for(int i=1 ; i<=N ; ++i) {
		if(visited[i] == false && matrix[x][i] == 1) {
			dfs(i);
		}
	}
}
//DFS

int main() {
	
	scanf("%d%d%d", &N, &M, &V);
	
	for(int i=0 ; i<M ; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	
	dfs(V);
	printf("\n");
	
	reset();
	
	bfs(V);
}

