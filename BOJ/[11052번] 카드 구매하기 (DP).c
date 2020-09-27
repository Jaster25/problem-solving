#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

int d[10001];
int p[10001];

int main() {
	
	int N;
	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; ++i) {
		scanf("%d", &p[i]);
	}
	
	d[1] = p[1];
	
	for(int i=2 ; i<=N ; ++i) {
		d[i] = p[i];
		
		for(int j=1 ; j<=i ; ++j) {
			d[i] = MAX(d[i], d[j]+d[i-j]);
		}
	}
	
	printf("%d", d[N]);
}
