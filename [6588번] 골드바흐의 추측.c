#include<stdio.h>
#define MAX 1000001

//에라토테네스의 접근 (소수 판별법)
//N이 소수이기 위한 필요 충분 조건은 N이 N의 제곱근보다
//크지 않은 어떤 소수로도 나눠지지 않는다. 

int prime[MAX];

int main() {
	
	for(int i=2 ; i<MAX ; ++i) prime[i] = 1;
	for(int i=2 ; i*i < MAX ; ++i) {
		for(int j=2 ; prime[i] && i*j < MAX ; ++j) {
			prime[i * j] = 0;
		}
	}
	
	int N;
	scanf("%d", &N);
	while(N != 0) {
		
		for(int i=2 ; i <= N/2 ; ++i) {
			
			if(prime[i] == 1 && prime[N-i] == 1) {
				printf("%d = %d + %d\n", N, i, N-i);
				break;
			}
		}
				
		scanf("%d", &N);
	}
}
