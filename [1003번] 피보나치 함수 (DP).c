#include<stdio.h>

long long dp[41];

long long fibonacci(int n) {

	if(n == 0 ) {
		return 0;	
	}
	else if(n == 1) {
		return 1;	
	}
	else if(dp[n] != 0){
		return dp[n];
	}
	
	dp[n] = fibonacci(n-1) + fibonacci(n-2);
	return dp[n];
}

int main() {
	
	int T;
	scanf("%d", &T);
	
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i=3; i<=40 ; ++i) {
		fibonacci(i);
	}
	
	for(int i=0 ; i<T ; ++i) {
		int N;
		scanf("%d", &N);
		
		if(N == 0) printf("1 0\n");
		else printf("%d %d\n", dp[N-1], dp[N]);
	}
}
