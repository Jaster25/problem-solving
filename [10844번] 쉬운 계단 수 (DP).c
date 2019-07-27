#include<stdio.h>

int d[101][10];

int main() {

	int N;
	scanf("%d", &N);
	
	//길이가 1이고 뒷자리가 i인 계단 수는 1개씩밖에 없다 - 기저 조건 
	for(int i=1 ; i<10 ; ++i) d[1][i] = 1;
	
	for(int i=2 ; i<=N ; ++i) {
		
		for(int j=0 ; j<10 ; ++j) {
			
			if(j==0) {
				d[i][j] = d[i-1][j+1] % 1000000000;
			}
			
			else if(j==9) {
				d[i][j] = d[i-1][j-1] % 1000000000;
			}
			
			else {
				d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
			}
		}	
	}
	
	//범위 벗어나지 않도록 주의 
	int sum = 0;
	for(int i=0 ; i<10 ; ++i) {
		sum = (sum + d[N][i]) % 1000000000;
	}
	
	printf("%d", sum);
}
