#include<iostream>
#include<vector>
#include<queue>
#define MAX 51
using namespace std;

int N, root, del, count;
vector<int> node[MAX];
bool visited[MAX];

void bfs(int start) {
	visited[start] = true;
	queue<int> q;
	q.push(start);
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		int childCount = 0;
		for(int i=0 ; i<node[now].size() ; ++i) {
			if(!visited[node[now][i]]) {
				childCount++;
				visited[node[now][i]] = true;
				q.push(node[now][i]);
			}
		}
		
		if(childCount == 0) count++;
	}
}

int main() {
	
	scanf("%d", &N);
	for(int i=0 ; i<N ; ++i) {
		int num;
		scanf("%d", &num);
		
		if(num != -1) {
			node[i].push_back(num);
			node[num].push_back(i);	
		}
		else {
			root = i;
		}
	}
	
	scanf("%d", &del);
	visited[del] = true;
	
	if(!visited[root]) bfs(root);
	
	printf("%d", count);	
}
