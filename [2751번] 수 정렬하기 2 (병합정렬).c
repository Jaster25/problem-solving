#include<stdio.h>
#define MAX 1000000

int array[MAX];
int sorted[MAX];

void merge(int *array, int start, int mid, int end) {
	
	int index = start;
	int first = start;
	int second = mid + 1;
	
	while(first <= mid && second <= end) {
		
		if(array[first] <= array[second])
			sorted[index++] = array[first++];
		else
			sorted[index++] = array[second++];
	}
	
	while(first <= mid)
		sorted[index++] = array[first++];
	while(second <= end)
		sorted[index++] = array[second++];
	
	
	for(int i=start ; i<=end ; ++i) {
		array[i] = sorted[i];
	}
}

void mergeSort(int *array, int start, int end) {
	
	if(start >= end) return;
	
	int mid = (start + end) / 2;

	mergeSort(array, start, mid);
	mergeSort(array, mid + 1, end);
	merge(array, start, mid, end);
}

int main() {
	
	int N;
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; ++i) {
		scanf("%d", &array[i]);
	}	
	
	mergeSort(array, 0, N-1);
	
	for(int i=0 ; i<N ; ++i) {
		printf("%d\n", array[i]);
	}
}
