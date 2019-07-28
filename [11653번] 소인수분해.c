#include<stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	
	int i=2;
	while(N > 1) {

		//더 좋은 풀이 
		if(N % i ==0) {
			printf("%d\n", i);
			N /= i;	
		}
		else i++;

//		for(int i=2 ; i<=N ; ++i) {
//			if(N % i == 0) {
//				printf("%d\n", i);
//				N /= i;
//				break;
//			}
//		}
	} 
}

