#include<stdio.h>
#define MAX 1001
typedef enum{false, true} bool;

int N;
int count;
int permutation[MAX];
bool visited[MAX];

void reset() {
	count = 0;
	for(int i=1 ; i<=N ; ++i)
		visited[i] = false;
}

void dfs(int a) {
	if(visited[permutation[a]] == false) {
		visited[permutation[a]] = true;
		dfs(permutation[a]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	
	while(T--) {
		reset();
		
		scanf("%d", &N);
		for(int i=1 ; i<=N ; ++i)
			scanf("%d", &permutation[i]);
		
		for(int i=1 ; i<=N ; ++i) {
			if(visited[i] == false) {
				visited[i] = true;
				dfs(i);
				count++;
			}
		}
		
		printf("%d\n", count); 
	}
}
