#include<stdio.h>

int N;
int ar[100001];

void quickSort(int ar[], int start, int end) {
	if(start >= end) return;
	
	int pivot = ar[start];
	int toRight = start + 1;
	int toLeft = end;
	
	while(toRight <= toLeft) {
		while(pivot >= ar[toRight] && toRight <= end) toRight++;
		while(pivot <= ar[toLeft] && toLeft >= start + 1) toLeft--;
		
		if(toRight <= toLeft) {
			int temp;
			temp = ar[toRight];
			ar[toRight] = ar[toLeft];
			ar[toLeft] = temp;
		}
		
		else {
			int temp;
			temp = ar[start];
			ar[start] = ar[toLeft];
			ar[toLeft] = temp;
		}
	}
	
	quickSort(ar, start, toLeft - 1);
	quickSort(ar, toLeft + 1, end);
}

int main() {
	
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &ar[i]);
	
	quickSort(ar, 0, N-1);
	
	printf("%d ", ar[0]);
	for(int i = 1; i < N; ++i)
		if(ar[i] != ar[i-1])
			printf("%d ", ar[i]);
}
