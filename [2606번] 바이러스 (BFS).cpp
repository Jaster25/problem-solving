#include<iostream>
#include<vector>
#include<queue>
#define MAX 101
using namespace std;

int N, M, count;
bool visited[MAX];
vector<int> computer[MAX];

void bfs(int start) {
	
	queue<int> Q;
	visited[start] = true;
	Q.push(start);
	
	while(!Q.empty()) {
		
		int now = Q.front();
		Q.pop();
		
		for(int i=0 ; i<computer[now].size() ; ++i) {
			int temp = computer[now][i];
			
			if(visited[temp] == false) {
				visited[temp] = true;
				Q.push(temp);
				count++;
			}
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

	bfs(1);

	printf("%d", count);
}
