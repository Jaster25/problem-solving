#include<stdio.h>
#define ull unsigned long long 

ull  dp[68];
//Ãâ·Â½Ã llu

ull koong(int i) {
	
	if(dp[i] != 0) return dp[i];
	
	
	dp[i] = koong(i - 1) + koong(i - 2) + koong(i - 3) + koong(i - 4);

	return dp[i];	
}
 
int main() {
	
	int t;
	scanf("%d", &t);
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for(int i=0 ; i<t ; ++i) {
		
		int N;
		scanf("%d", &N);
		
		printf("%llu\n", koong(N));
	}
}
