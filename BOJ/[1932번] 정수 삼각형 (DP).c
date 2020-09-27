#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

int dp[501][501];
int ar[501][501];

int main() {
	
	int N;
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; ++i) {
		for(int j=1 ; j<=i ; ++j) {
			scanf("%d", &ar[i][j]);
		}
	}
	
	//초기 설정 
	for(int i=1 ; i<=N ; ++i) dp[N][i] = ar[N][i];
	
	for(int i=N-1 ; i>=1 ; --i) {
		for(int j=1 ; j<=N-1 ; ++j) {
			dp[i][j] = MAX(dp[i+1][j], dp[i+1][j+1]) + ar[i][j];
		}
	}
	
	printf("%d", dp[1][1]);
}
