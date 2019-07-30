#include<iostream>
using namespace std;

#define min(a,b) (a<b ? a : b)
#define MAX 100000000

int N, M;
int graph[101][101];

//플로이드 가능한 이유 N<=100
void floyd() {
	
	//거쳐가는 도시 먼저!
	for(int k=1 ; k<= N ; ++k) {
		for(int y=1 ; y<=N ; ++y) {
			for(int x=1 ; x<=N ; ++x) {
				if(graph[y][x] > graph[y][k] + graph[k][x]) {
					graph[y][x] = graph[y][k] + graph[k][x];
				}
			}
		}
	}
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=N ; ++j)
			i == j ? graph[i][j] = 0 : graph[i][j] = MAX;
				
	for(int i=0 ; i<M ; ++i) {
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a][b] = min(graph[a][b], c);
	}
	
	floyd();
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			if(graph[i][j] == MAX) printf("0 ");
			else printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}
