#include<stdio.h>

void binary(int n) {
	if(n == 0) return ;
	 
	if(n % -2 == 0) {
	
		binary(n / -2);
		printf("0");
	}
	else {
		
		binary( (n-1) / -2);
		printf("1");
	}
}

int main() {
	
	int N;
	scanf("%d", &N);
	
	if(N == 0) printf("0");
	else {
			
		binary(N);	
	}
	
}
