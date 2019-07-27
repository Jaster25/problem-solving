#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

int d[22];
int T[1001];
int pay[1001];

int main() {
	
	int N;
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; ++i) {
		scanf("%d%d", &T[i], &pay[i]);
	}
	
	for(int i=1 ; i<=N ; ++i) {
		
		d[i + 1] = MAX(d[i + 1], d[i]);
		d[i + T[i]] = MAX(d[i + T[i]], d[i] + pay[i]);
		
		//d[i] = MAX(d[i+1], d[i+T[i]]+ p[i])
	}
	
	printf("%d", d[N+1]);
}
