#include<stdio.h>
#define MIN(a,b) (a<b ? a : b)

//Memoization
int dp[10000000] = {0,};

int makeOne(int i) {
	
	if(i==0 || i==1) return 0;
	
	if(dp[i-1] == 0) makeOne(i-1);
	if(dp[i/2] == 0) makeOne(i/2);
	if(dp[i/3] == 0) makeOne(i/3);

	dp[i] = dp[i-1] + 1;
	if(i%2 == 0) dp[i] = MIN(dp[i], dp[i/2] + 1); 
	if(i%3 == 0) dp[i] = MIN(dp[i], dp[i/3] + 1); 
	
	return dp[i];	
}
int main() {
	
	int X;
	scanf("%d", &X);

	printf("%d", makeOne(X));
}
