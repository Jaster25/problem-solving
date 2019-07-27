#include<stdio.h>
#define ll long long

int main() {
	ll a,b,c,d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	
	char str[10000];
	sprintf(str, "%lld%lld %lld%lld", a,b,c,d);
	
	ll x;
	ll y;
	
	sscanf(str, "%lld %lld", &x, &y);
	printf("%lld", x+y);
}

