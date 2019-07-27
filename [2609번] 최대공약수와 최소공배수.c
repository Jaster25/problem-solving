#include<stdio.h>

int main() {
	int a,b;
	scanf("%d%d", &a, &b);
	
	int gcd;
	
	//a * b = gcd * lcm
	//¼ôÄÚµù for(c=a>b?a:b;a%c||b%c;c--); 
	if(a<b) {
		for(int i=a ; i>=1 ; --i) {
			if(a%i==0 && b%i==0) {
				gcd = i;
				break;
			}
		}
	}
	else {
		for(int i=b ; i>=1 ; --i) {
			if(a%i==0 && b%i==0) {
				gcd = i;
				break;
			}
		}
	}
	
	int lcm;
	
	if(a<b) {
		for(int i=a ; ; ++i) {
			if(i%a==0 && i%b==0) {
				lcm = i;
				break;
			}
		}
	}
	else {
		for(int i=b ; ; ++i) {
			if(i%a==0 && i%b==0) {
				lcm = i;
				break;
			}
		}
	}
	
	printf("%d\n%d", gcd, lcm);
}
