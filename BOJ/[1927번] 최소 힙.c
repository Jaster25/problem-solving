#include<stdio.h>

int N, x, count;
int ar[100001];

void swap(int a, int b) {
	int temp = ar[a];
	ar[a] = ar[b];
	ar[b] = temp;
}

void insertHeap(int num) {
	
	ar[++count] = num;
	
	int index = count;
	while(index > 1) {
		
		if(ar[index] < ar[index/2]) {
			swap(index, index/2);
			index /= 2;
		}
		else
			break;
	}
}

void deleteHeap() {
	
	if(count == 0) {
		printf("0\n");
		return;
	}
	
	printf("%d\n", ar[1]);
	swap(1, count--);
	
	int index = 1;
	while(index <= count/2) {
		
		int child = index*2;
		if(child+1 <= count && ar[child] > ar[child+1])
			child++;
		
		if(ar[child] < ar[index]) {
			swap(child, index);
			index = child;
		}
		else
			break;
	}
}

int main() {
	
	scanf("%d", &N);
	
	while(N--) {
		
		scanf("%d", &x);

		if(x == 0)
			deleteHeap();
		else
			insertHeap(x);
	}
}
