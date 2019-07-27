#include<stdio.h>
#define MIN(a,b) (a<b ? a : b)
#include<math.h>

//j의 최대 값만으로 풀면 틀린다 ex 12인 경우
//이중 반복문으로 돌려도 저장값이 있어 n*n이 안나오는듯
 
int dp[1000001] = {0,};

int main() {

	int N;
	scanf("%d", &N);

	dp[1] = 1;
	
	for(int i=1 ; i<=N ; ++i) {
		
		dp[i] = i;
		for(int j=1 ; j<=(int)sqrt(i) ; ++j) {
			dp[i] = MIN(dp[i], dp[i-j*j] + 1);
		}
	}
		
	printf("%d", dp[N]);
} 
