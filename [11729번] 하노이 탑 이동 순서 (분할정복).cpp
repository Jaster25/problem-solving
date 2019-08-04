#include<iostream>
#include<utility>
#include<queue>
#define MAX 21
using namespace std;

int N, cnt;
queue<pair<int,int> > Q;

void hanoi(int num, int from, int bridge, int to) {
	cnt++;
	
	if(num == 1) {
		Q.push(pair<int,int>(from, to));
	}
	
	else {
		hanoi(num-1, from, to, bridge);
		Q.push(pair<int,int>(from, to));
		hanoi(num-1, bridge, from, to);
	}
}

int main() {
	scanf("%d", &N);
	
	hanoi(N, 1, 2, 3);
	
	printf("%d\n", cnt);
	while(!Q.empty()) {
		printf("%d %d\n", Q.front().first, Q.front().second);
		Q.pop();
	}
}
