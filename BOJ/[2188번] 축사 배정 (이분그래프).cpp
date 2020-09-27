#include<stdio.h>
#include<vector>
#define MAX 201
using namespace std;

vector<int> want[MAX];
int yard[MAX];
bool visited[MAX];

bool solve(int);

int main() {
	
	int N,M;
	scanf("%d%d", &N, &M);
	
	int numberOfChoice, choice;
	for(int i=1 ; i<=N ; ++i) {
		scanf("%d", &numberOfChoice);
		while(numberOfChoice--) {
			scanf("%d", &choice);
			want[i].push_back(choice);
		}
	}
	
	int ans = 0;
	for(int i=1 ; i<=N ; ++i) {
		fill(visited, visited+N, false);
		if(solve(i))
			++ans;
	}
	
	printf("%d", ans);
}

bool solve(int num) {
	
	if(visited[num])
		return false;
	
	visited[num] = true;
	for(auto i : want[num]) {
		if(!yard[i] || solve(yard[i])) {
			yard[i] = num;
			return true;
		}
	}
	
	return false;
}
