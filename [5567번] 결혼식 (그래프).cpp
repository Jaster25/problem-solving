#include<iostream>
#include<vector>
using namespace std;

#define MAX 501

int N, M;
int count;

vector<int> list[MAX];
bool visited[MAX];

void findFriends(int a) {
	visited[a] = true;
	
	for(int i=0 ; i<list[a].size() ; ++i) {
			
		visited[list[a][i]] = true;
			
		vector<int> friend1 = list[list[a][i]];
		for(int j=0 ; j<friend1.size() ; ++j) {
			visited[friend1[j]] = true;
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for(int i=1 ; i<=M ; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		
		list[a].push_back(b);
		list[b].push_back(a);
	}
	
	findFriends(1);
	
	for(int i=2 ; i<=N ; ++i)
		if(visited[i] == true) count++;
	
	printf("%d", count);
}
