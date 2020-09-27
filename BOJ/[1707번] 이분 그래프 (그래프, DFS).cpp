#include<iostream>
#include<vector>
#define  MAX 20001
using namespace std;

int K, V, E;
vector<int> graph[MAX];
int color[MAX];
bool bipartite;

void reset() {
	
	bipartite = true;
	for(int i=0 ; i <= V ; ++i) {
		color[i] = 0;
		graph[i].clear();
	}
}

void dfs(int num) {
	
	int coloring = color[num] * -1;
	
	for(int i=0 ; i<graph[num].size() ; ++i) {
		int next = graph[num][i];
		
		if(color[next] == 0) {
			color[next] = coloring;
			dfs(next);
		}
		else if(color[next] != coloring)
			bipartite = false;
	}
}

int main() {
	
	scanf("%d", &K);
	
	while(K--) {
		scanf("%d%d", &V, &E);
		reset();
		
		for(int i=0 ; i<E ; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		for(int i=1 ; i<=V ; ++i) {
			if(color[i] == 0)  {
				color[i] = 1;
				dfs(i);
			}
		}
		
		if(bipartite == false) printf("NO\n");
		else printf("YES\n");
	}
}
