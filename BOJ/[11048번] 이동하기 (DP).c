#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

int dp[1001][1001] = {0,};
int candy[1001][1001] = {0,};

int main() {
	
	int N,M;
	scanf("%d%d", &N, &M);
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=M ; ++j)
			scanf("%d", &candy[i][j]);

	dp[1][1] = candy[1][1];
	
	//(i+1, j), (i, j+1), (i+1, j+1) 3¹æÇâ»Ó 
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=M ; ++j) {
			
			if(i==1 && j==1) continue;
		
			dp[i][j] = MAX( MAX(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1] ) + candy[i][j];
		}
	}
	
	printf("%d", dp[N][M]);
}
