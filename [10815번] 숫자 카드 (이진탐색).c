#include<stdio.h>
#define ll long long

int N, M;
ll card[500001];

void quickSort(ll ar[], int start, int end) {
	if(start >= end) return;

	ll pivot = ar[start];
	int toRight = start + 1;
	int toLeft = end;
	
	while(toRight <= toLeft) {
		while(ar[toRight] <= pivot && toRight <= end)
			toRight++;
		while(ar[toLeft] >= pivot && toLeft >= start + 1)
			toLeft--;
			
		if(toRight > toLeft) {
			ll temp = ar[toLeft];
			ar[toLeft] = ar[start];
			ar[start] = temp;
		}
		else {
			ll temp = ar[toLeft];
			ar[toLeft] = ar[toRight];
			ar[toRight] = temp;
		}
	}
	
	quickSort(ar, start, toLeft - 1);
	quickSort(ar, toLeft + 1, end);
}

void find(int num) {
	
	int left = 0;
	int right = N-1;
	
	while(left <= right) {
		
		int mid = (left + right) / 2;
		
		if(num >= card[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	
	if(card[right] == num) printf("1 ");
	else printf("0 ");
}

int main() {
	
	scanf("%d", &N);
	for(int i=0 ; i<N ; ++i)
		scanf("%lld", &card[i]);
		
	quickSort(card, 0, N-1);
	
	scanf("%d", &M);
	while(M--) {
		int test;
		scanf("%d", &test);
		
		find(test);
	}
}
