#include<stdio.h>
#include<stdlib.h>

int N, M;
int A[100001], find;

int compare(void* a, void* b) {
	int A = *(int*)a; 
	int B = *(int*)b;
	
	return A > B;
}

int search(int find) {
	
	int left = 0;
	int right = N-1;
	
	while(left <= right) {

		int mid = (left + right) / 2;
				
		if(A[mid] == find)
			return 1;
			
		else if(A[mid] > find)
			right = mid - 1;
		else
			left = mid + 1;
	}
	
	return 0;
}

int main() {
	
	scanf("%d", &N);
	for(int i=0 ; i<N ; ++i)
		scanf("%d", &A[i]);
	
	qsort(A, N, sizeof(int), compare);

	scanf("%d", &M);
	
	while(M--) {
		scanf("%d", &find);
		printf("%d\n", search(find));
	} 
}
