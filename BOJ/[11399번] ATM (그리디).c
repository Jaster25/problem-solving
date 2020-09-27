#include<stdio.h>
#define ll long long

int N;
int time[1001];
int sorted[1001];

void merge(int *ar, int start, int mid, int end) {
	int first = start;
	int second = mid + 1;
	int index = start;
	
	while(first <= mid && second <= end) {
		if(ar[first] <= ar[second]) sorted[index++] = ar[first++];
		else sorted[index++] = ar[second++];
	}
	
	while(first <= mid) sorted[index++] = ar[first++];
	while(second <= end) sorted[index++] = ar[second++];
	
	for(index = start ; index <= end ; ++index) ar[index] = sorted[index];
}

void mergeSort(int *ar, int start, int end) {
	if(start >= end) return;
	
	int mid = (start + end) / 2;
	mergeSort(ar, start, mid);
	mergeSort(ar, mid + 1, end);
	merge(ar, start, mid, end);
}

ll sum(int i) {
	ll sum = 0;
	
	for(int j=0 ; j<=i ; ++j) {
		sum += time[j];
	}
	
	return sum;	
}

int main() {
	
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; ++i) scanf("%d", &time[i]);
	
	mergeSort(time, 0, N-1);
	
	ll min = 0;
	for(int i=0 ; i<N ; ++i) {
		min += sum(i);
	}
	
	printf("%lld", min);
}
