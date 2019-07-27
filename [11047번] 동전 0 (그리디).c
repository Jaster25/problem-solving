#include<stdio.h>

int N,K;
int coin[10];

int main() {
	
	scanf("%d%d", &N, &K);
	
	for(int i=0 ; i<N ; ++i) {
		scanf("%d", &coin[i]);
	}
	
	int count = 0;
	while(K != 0) {
		for(int i=N-1 ; i>=0 ; --i) {
			if(coin[i] <= K) {
				K -= coin[i];
				count++;
				break;
			}
		}
	}
	
	printf("%d", count);
}
