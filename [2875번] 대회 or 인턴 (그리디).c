#include<stdio.h>

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	
	int count = 0;
	int total = N + M - K;

	while(N>1 && M>0 && total>2) {
		N -= 2;
		M -= 1;
		total -= 3;
		count++;
	}
	
	printf("%d", count);
}
