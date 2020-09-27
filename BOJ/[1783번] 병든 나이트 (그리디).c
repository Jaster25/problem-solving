#include<stdio.h>
#define MIN(a,b) (a<b ? a : b)

int main() {
	int n, m, count;
	scanf("%d%d", &n, &m);
	
	if(n == 1) count = 1;
	else if(n == 2) count = MIN(4, (m+1)/2);
	else if(m < 7) count = MIN(4, m);
	else count = m-2;
	
	printf("%d", count);
}
