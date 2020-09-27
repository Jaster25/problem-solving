#include<stdio.h>
#define ll unsigned long long

ll dp[101];

int main() {
	
	int N;
	scanf("%d", &N);
	
	//�ʱⰪ
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 3;
	
	for(int i=6 ; i<=100 ; ++i) {
		dp[i] = dp[i-1] + dp[i-5];
	}	
	
	for(int i=0 ; i<N ; ++i) {
		int x;
		scanf("%d", &x);
		printf("%llu\n", dp[x-1]);
	}
}
