#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 101

typedef struct Node {
	
	int connect[MAX];
	int cnt;
} Node;

int N, M, count;
Node *computer[MAX];
bool visited[MAX];

void createNode(int num) {
	
	for(int i=1 ; i<=N ; ++i) {
		computer[i] = (Node*) malloc (sizeof(Node));
		computer[i]->cnt = 0;
	}
}

void dfs(int start) {
	
	for(int i=1 ; i<=computer[start]->cnt ; ++i) {
		int temp = computer[start]->connect[i];
		
		if(visited[temp] == false) {
			visited[temp] = true;
			count++;
			dfs(temp);
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	createNode(N);
	
	while(M--) {
		
		int a,b;
		scanf("%d%d", &a, &b);
		
		computer[a]->connect[++computer[a]->cnt] = b;
		computer[b]->connect[++computer[b]->cnt] = a;
	}	

	visited[1] = true;
	dfs(1);

	printf("%d", count);
}
