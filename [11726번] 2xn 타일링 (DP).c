#include<stdio.h>

int d[10000];

int dp(int n) {
	
	if(n == 1) return 1;
	else if(n == 2) return 2;
	
	if(d[n] != 0) return d[n];
	else return d[n] = ( dp(n-1) + dp(n-2) ) % 10007;
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	printf("%d", dp(n));
}
