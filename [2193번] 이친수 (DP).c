#include<stdio.h>
#define ll long long

ll d[91][2];

int main() {
	
	int N;
	scanf("%d", &N);
	
	//기저 조건 
	d[1][0] = 0;
	d[1][1] = 1;
	
	for(int i=2 ; i<=N ; ++i) {
		
		d[i][0] = d[i-1][0] + d[i-1][1];
		d[i][1] = d[i-1][0];
	}
	
	ll result = (d[N][0] + d[N][1]);
	printf("%lld", result);
}
