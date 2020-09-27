#include<stdio.h>

int d[1000001];

int main() {
	
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;
	d[4] = 5;
	
	int N;
	scanf("%d", &N);
	
	for(int i=5 ; i<=N ; ++i) {
	
		d[i] = ( d[i-2] % 15746 + d[i-1] % 15746 ) % 15746;
	}
	
	printf("%d", d[N]);
}
