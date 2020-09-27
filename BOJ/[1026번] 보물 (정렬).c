#include<stdio.h>
#include<stdlib.h>
#define MAX 101

int A[MAX];
int B[MAX];

int compare(void* a, void* b) {
	return (*(int*)a < *(int*)b) * 2 - 1;
}

int main() {
	
	int N;
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; ++i) scanf("%d", &A[i]);
	for(int i=0 ; i<N ; ++i) scanf("%d", &B[i]);
	
	qsort(A, N, sizeof(int), compare);
	qsort(B, N, sizeof(int), compare);
	
	int min = 0;
	for(int i=0 ; i<N ; ++i) min += A[i] * B[N - i - 1];

	printf("%d", min);
}
