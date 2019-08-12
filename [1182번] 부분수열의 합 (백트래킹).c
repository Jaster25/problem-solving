#include<stdio.h>
#include<stdlib.h>

int N, S;
int ar[21];
int sum, count;

int compare(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

void search(int index) {
	
	if(index == N - 1) {
		if(sum == S)
			count++;
			
		return;
	}

	sum += ar[index + 1];
	search(index + 1);

	sum -= ar[index + 1];
	search(index + 1);
}

int main() {

	scanf("%d%d", &N, &S);
	for(int i=0 ; i<N ; ++i)
		scanf("%d", &ar[i]);
	
	qsort(ar, N, sizeof(int), compare);
	
	for(int i=0 ; i<N ; ++i) {
		sum = ar[i];
		search(i);
	}
	
	printf("%d", count);
}
