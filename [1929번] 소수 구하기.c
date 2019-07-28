#include<stdio.h>
#include<math.h> 
#define MAX 1000001

int M, N;
int notPrime[MAX];

int main() {
	scanf("%d%d", &M, &N);
	
	for(int i=M ; i<=N ; ++i) {
		
		if(i == 1) notPrime[i] = 1;
		
		for(int j=2 ; j<=sqrt(i) ; ++j) {
			
			if(i % j == 0) {
				notPrime[i] = 1;
				break;
			}
		}
		
		if(notPrime[i] == 0) printf("%d\n", i);
	}
}
