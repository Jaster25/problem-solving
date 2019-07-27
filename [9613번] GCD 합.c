#include<stdio.h>

int num[101];

int findGCD(int a, int b) {
	
	if(a<b) {
		for(int i=a ; i>=1 ; --i) {
			if(a%i == 0 && b%i == 0) return i;
		}
	}
	
	else {
		for(int i=b ; i>=1 ; --i) {
			if(a%i == 0 && b%i == 0) return i;
		}
	}
	
	return 1;
}

int main() {
	int T;
	scanf("%d", &T);
	
	while(T--) {
		
		long long GCD = 0;
		
		int k;
		scanf("%d", &k);
		
		for(int i=0 ; i<k ; ++i) {
			scanf("%d", &num[i]);
		}
		
		for(int i=0 ; i<k-1 ; ++i) {
			for(int j=i+1 ; j<k ; ++j) {
				GCD += findGCD(num[i], num[j]);
			}
		}

		printf("%lld\n", GCD);
	}
}
