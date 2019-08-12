#include<stdio.h>
#include<stdlib.h>

int A, n[51];

int compare(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int main() {
	
	scanf("%d", &A);

	for(int i=0 ; i<A ; ++i)
		scanf("%d", &n[i]);
	
	qsort(n, A, sizeof(n[0]), compare);
	
	printf("%d", n[0] * n[A-1]);
}
