#include<stdio.h>
#define MAX 1000001

int N, M;
int A[MAX], B[MAX];
int first, second;

int main() {
	scanf("%d%d", &N, &M);
	
	for(int i=0 ; i<N ; ++i)
		scanf("%d", &A[i]);
	for(int i=0 ; i<M ; ++i)
		scanf("%d", &B[i]);
		
	while(first < N && second < M) {
		if(A[first] <= B[second])
			printf("%d ", A[first++]);
		else
			printf("%d ", B[second++]);
	}
	
	while(first < N)
		printf("%d ", A[first++]);
	while(second < M)
		printf("%d ", B[second++]);
}
