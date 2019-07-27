#include<stdio.h>
#define MAX 10001

int dp[MAX];
int coin[21];
int coinNumber;
int money;

void dpReset() {
	dp[0] = 1;
	for(int i=1 ; i<MAX ; ++i) {
		dp[i] = 0;
	}
}
		
int main() {
	
	int T;
	scanf("%d", &T);
	
	while(T--) {
		
		dpReset();
		
		scanf("%d", &coinNumber);
		for(int j=0 ; j<coinNumber ; ++j) {
			scanf("%d", &coin[j]);
		}

		scanf("%d", &money);
		
		for(int k=0 ; k<coinNumber ; ++k) {
			for(int i=coin[k] ; i<=money ; ++i) {
				dp[i] += dp[i-coin[k]];
			}
		}

		printf("%d\n", dp[money]);
	}
}
