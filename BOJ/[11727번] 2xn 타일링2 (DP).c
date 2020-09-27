#include<stdio.h>
typedef long long ll;

ll d[10000];

ll dp(int i) {
	
	if(i <= 1) return 1;
	else if(i == 2) return 3;
	
	if(d[i] != 0) return d[i];
	else  return d[i] = (dp(i-1) + 2 * dp(i-2)) % 10007;
}

int main() {
	
	int N;
	scanf("%d", &N);
	
	printf("%lld", dp(N));
}

//--------------------------------------------------

#include<stdio.h>

int d[1001];

int main() {
	
	int n;
	scanf("%d", &n);
	
	//기저 조건
	d[1] = 1;
	d[2] = 3;
	d[3] = 5; 
	
	
	for(int i=4 ; i<=n ; ++i) {
		d[i] = ( d[i-1] % 10007 + d[i-2] * 2  % 10007 ) % 10007;
	}	
	
	printf("%d", d[n]);
}
