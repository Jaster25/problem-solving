#include<stdio.h>
#include<math.h>
#define MAX 1001
// 에라토스테네스의 체 

int N, num;

int main() {
	
	scanf("%d", &N);
	int count = N;
	
	while(N--) {
		
		scanf("%d", &num);
		
		if(num == 1) count--;
		
		for(int i=2 ; i<=sqrt(num) ; ++i) {
			if(num % i == 0) {
				count--;
				break;
			}
		}
	}
	
	printf("%d", count); 
}
