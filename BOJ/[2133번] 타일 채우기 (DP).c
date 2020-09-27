#include<stdio.h>

int d[1000];


int main() {
	
	int N;
	scanf("%d", &N);
	
	//기저 조건
	d[0] = 1;
	d[2] = 3;
	
	for(int i=4 ; i<=N ; i+=2) {
		
		//일반적인 경우 
		d[i] = d[i-2] * 3;
		
		//맨위 또는 맨밑 줄 전부  가로 타일
		for(int j=4 ; i-j>=0 ; j+=2) d[i] += d[i - j] * 2;
	}
	
	printf("%d", d[N]);
}
