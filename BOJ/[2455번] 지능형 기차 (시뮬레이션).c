#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

int max, now;

int main() {
	
	for(int i=0 ; i<4 ; ++i) {
		int a,b;
		scanf("%d%d", &a, &b);
		
		now = now - a + b;
		max = MAX(max, now);
	}
		
	printf("%d", max);	
}
