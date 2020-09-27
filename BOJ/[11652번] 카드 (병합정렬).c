#include<stdio.h>
#define ll long long
#define MAX 1000000
#define TYPE long long 

TYPE ar[MAX];
TYPE sorted[MAX];

void merge(TYPE ar[], int start, int mid, int end) {
	
	int index = start;
	int first = start;
	int second = mid + 1;
	
	while(first <= mid && second <= end) {
		if(ar[first] <= ar[second]) sorted[index++] = ar[first++];
		else sorted[index++] = ar[second++];
	}
	
	while(first <= mid) sorted[index++] = ar[first++];
	while(second <= end) sorted[index++] = ar[second++];
	
	for(int i=start ; i<=end ; ++i) {
		ar[i] = sorted[i];
	}
}

void mergeSort(TYPE ar[], int start, int end) {
	if(start >= end) return;
	
	int mid = (start + end) / 2;
	
	mergeSort(ar, start, mid);
	mergeSort(ar, mid + 1, end);
	merge(ar, start, mid, end);
}


int main() {
	
	int N;
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; ++i) {
		scanf("%lld", &ar[i]);
	}
	
	mergeSort(ar, 0, N-1);
	
	//�ʱⰪ 
	int maxCount = 1;
	int count = 1;
	ll maxNum = ar[0];
	
	for(int i=1 ; i<N ; ++i) {
		
		if(ar[i] == ar[i-1]) {
			count++;
		}
		else {
			count = 1;
		}
		
		if(count > maxCount) {
			maxCount = count;
			maxNum = ar[i];
		}
	}
	
	printf("%lld", maxNum);
}
