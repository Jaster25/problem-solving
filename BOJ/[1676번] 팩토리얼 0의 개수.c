#include<stdio.h>

//5의 개수만 확인 

int N;
int count = 0;

int main() {
	
	scanf("%d", &N);
	
	while(N > 0) {
		count += N/5;
		N /= 5;
	}
	
	printf("%d", count);
}
