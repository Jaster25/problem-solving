#include<iostream>
#include<string.h>
#define MAX 100001
using namespace std;

int N, count;
int student[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int a) {
	
	visited[a] = true;
	int next = student[a];
	
	if(!visited[next])
		dfs(next);

	//이미 방문했지만 방문이 진행중이라면 싸이클이란 뜻 
	else if(!done[next]) {
		//팀원 수 
		for(int i = next; i != a; i = student[i])
			count++;
		//자기 자신 
		count++;
	}
	
	done[a] = true;
}

void reset() {
	count = 0;
	memset(visited, false, N+1);
	memset(done, false, N+1);
}

int main() {
	
	int T;
	scanf("%d", &T);
	
	while(T--) {
		reset();
		scanf("%d", &N);
		
		for(int i=1 ; i<=N ; ++i)
			scanf("%d", &student[i]);
		
		for(int i=1 ; i<=N ; ++i)
			if(!visited[i]) dfs(i);
		
		printf("%d\n", N - count);
	}
}
