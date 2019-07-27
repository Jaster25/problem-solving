#include<stdio.h>

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int i=0 ; i<T ; ++i) {
		
		int a,b,c;
		scanf("%d%d", &a, &b);
		
		for(c = a<b ? a:b ; a%c || b%c ; --c);
		
		int lcm = a*b/c;
		
		printf("%d\n", lcm);
	}
}

