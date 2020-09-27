#include<stdio.h>

//유클리드 호제법
//x를 y로 나눈(뺸) 나머지 값을 R이라고 했을 떄,
//x와 y의 최대공약수는 y와 r의 최대공약수와 같다 

int a,b;
int gcd, lcm;

int GCD(int x, int y) {
	if(y==0) return x;
	
	GCD(y, x % y);
}

int main() {
	
	scanf("%d%d", &a, &b);

	if(a>b) gcd = GCD(a,b);
	else gcd = GCD(b,a);
	
	lcm = a * b / gcd;
	
	printf("%d\n%d", gcd, lcm);
}
