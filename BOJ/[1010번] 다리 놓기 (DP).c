#include<stdio.h>
#define ll long long
#define MAX 31

//조합의 성질 
//파스칼의 삼각형 n C r = n-1 C r-1 +n-1 C r
//n C n == n C 0 == 1

ll dp[MAX][MAX];

void solve() {
	
	for(int i=0 ; i<MAX ; ++i) {
		dp[i][0] = dp[i][i] = 1;
		
		for(int j=1 ; j<=i-1 ; ++j) {
	 		dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
}

int main() {
	
	int N, M;
	int T;
	scanf("%d", &T);

	solve();
	
	while(T--) {
		scanf("%d%d", &N, &M);
		printf("%d\n", dp[M][N]);
	}
}
