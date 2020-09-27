#include<iostream>
using namespace std;

#define MAX 21

int N, sum = 0;
int graph[MAX][MAX];
int useless[MAX][MAX];

void floydReverse() {

	for(int k=1 ; k<=N ; ++k) {
		for(int y=1 ; y<=N ; ++y) {
			for(int x=1 ; x<=N ; ++x) {
				if(graph[y][x] > graph[y][k] + graph[k][x]) {
					printf("-1");
					exit(0);
				}
				
				if(k == y || k == x || x == y)
					continue;
				
				if(graph[y][x] == graph[y][k] + graph[k][x])
					useless[y][x] = 1;
			}
		}
	}
}

int main() {
	
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=N ; ++j)
			scanf("%d", &graph[i][j]);
			
	floydReverse();
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=N ; ++j) {
			if(!useless[i][j]) sum += graph[i][j];
		}
	}
	
	printf("%d", sum / 2);
}
