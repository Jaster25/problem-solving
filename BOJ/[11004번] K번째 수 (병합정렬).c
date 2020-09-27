#include<stdio.h>

int ar[5000001];
int sorted[5000001];

void merge(int ar[], int start, int mid, int end) {
	
	int index = start;
	int first = start;
	int second = mid + 1;
	
	while(first <= mid && second <= end) {
		if(ar[first] <= ar[second]) sorted[index++] = ar[first++];
		else sorted[index++] = ar[second++];
	}
	
	while(first <= mid) sorted[index++] = ar[first++];
	while(second <= end) sorted[index++] = ar[second++];
	
	for(int i=start ; i<=end ; ++i) ar[i] = sorted[i];
}

void mergeSort(int ar[], int start, int end) {
	
	if(start >= end) return;
	
	int mid = (start + end) / 2;
	
	mergeSort(ar, start, mid);
	mergeSort(ar, mid+1, end);
	merge(ar, start, mid, end);
}

int main() {

	int N, K;
	scanf("%d%d", &N, &K);
	
	for(int i=0 ; i<N ; ++i) scanf("%d", &ar[i]);
	
	mergeSort(ar, 0, N-1);
	
	printf("%d", ar[K-1]);
}
