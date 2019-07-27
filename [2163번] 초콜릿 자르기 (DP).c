#include<stdio.h>

int main() {
	
	int min;
	int N,M;
	scanf("%d%d", &N, &M);
	
	if(N<M) min = (N-1) + N * (M-1);
	
	else {
		min = (M-1) + M * (N-1);
	}
	
	printf("%d", min);
}
