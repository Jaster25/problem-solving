#include<stdio.h>

int N, fac;

int main() {

	scanf("%d", &N);

	fac = 1;
	while(N) fac *= N--;
	
	printf("%d", fac);
} 
