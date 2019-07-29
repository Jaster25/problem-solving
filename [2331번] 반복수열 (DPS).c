#include<stdio.h>
#include<math.h>
#define MAX 1000000

int A, P;
int count;

int visited[MAX];

int func(int a) {
	int sum = 0;
	while(a > 0) {
		sum += pow(a % 10, P);
		a /= 10;
	}
	
	return sum;
}

void dfs(int a) {
	visited[a]++;
	
	if(visited[a] == 3) return;
	else dfs(func(a));
}

int main() {
	scanf("%d %d", &A, &P);
	
	dfs(A);
	
	for(int i=1 ; i<MAX ; ++i)
		if(visited[i] == 1) count++;
	
	printf("%d", count);
}
