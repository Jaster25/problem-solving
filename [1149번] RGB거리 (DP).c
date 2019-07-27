#include<stdio.h>
#define MIN(a,b) (a<b ? a : b)

int d[1001][3];
int price[1001][3];

int main() {
	
	int N;
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; ++i) {
		scanf("%d%d%d", &price[i][0], &price[i][1], &price[i][2]);
	}
	
	//�ʱⰪ 
	d[1][0] = price[1][0];
	d[1][1] = price[1][1];
	d[1][2] = price[1][2];
	
	for(int i=2 ; i<=N ; ++i) {
		
		d[i][0] = MIN( d[i-1][1], d[i-1][2] ) + price[i][0];
		d[i][1] = MIN( d[i-1][0], d[i-1][2] ) + price[i][1];
		d[i][2] = MIN( d[i-1][0], d[i-1][1] ) + price[i][2];
	}
	
	int min = MIN(d[N][0], d[N][1]);
	min = MIN(min, d[N][2]);
	
	printf("%d", min);
} 
