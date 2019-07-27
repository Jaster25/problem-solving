#include<stdio.h>
#include<string.h>

//입력의 수가 10000000개로 일반적인 풀이로느 메모리 초과 발생함 
//값들이 10000이하여서 정렬말고 카운팅하는 풀이 

int ar[10001] = {0,};

int main() {
	
	int N;
	scanf("%d", &N);
	
	int num;
	for(int i=0 ; i<N ; ++i) {
		scanf("%d", &num);
		ar[num]++;
	}
	
	for(int i=1 ; i<=10000 ; ++i) {
		while(ar[i] >= 1) {
			printf("%d\n", i);
			ar[i]--;
		}
	}
}
