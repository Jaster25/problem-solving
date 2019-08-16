#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

int N, M, count;
vector<int> computer[MAX];
bool visited[MAX];

void dfs(int start) {
	
	for(int i=0 ; i<computer[start].size() ; ++i) {
		int temp = computer[start][i];
		
		if(visited[temp] == false) {
			visited[temp] = true;
			count++;
			dfs(temp);
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	while(M--) {
		
		int a,b;
		scanf("%d%d", &a, &b);
		
		computer[a].push_back(b);
		computer[b].push_back(a);
	}	

	visited[1] = true;
	dfs(1);

	printf("%d", count);
}
