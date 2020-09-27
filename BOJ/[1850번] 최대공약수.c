#include<stdio.h>
#define ll long long
//최대공약수 알고리즘 : 유클리드 호제법 
 
int euclid(ll u, ll v) {
	return (u % v == 0 ? v : euclid(v, u % v));	
}

int main() {
	ll A,B;
	scanf("%lld%lld", &A, &B);
	
	for(int i=0 ; i<euclid(A,B) ; ++i) {
		printf("1");
	}
}
