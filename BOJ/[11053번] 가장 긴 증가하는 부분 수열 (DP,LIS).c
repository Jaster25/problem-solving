#include<stdio.h>


/*
//O(n * n) 시간복잡도 풀이

int d[1001];
int seq[1001];

int main() {
	
	//max=0 으로 초기화할 경우 1 1 입력시 0 출력 
	int max=1;
	int n;
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; ++i) {
		scanf("%d", &seq[i]);
	}
	
	//기저 조건 
	d[1] = 1;
	
	for(int i=2 ; i<=n ; ++i) {
		
		d[i] = 1;
		for(int j=1 ; j<=i ; ++j) {
			if(seq[i] > seq[j] && d[i] <= d[j]) {
				d[i] = d[j] + 1;
			}
		}
		
		if(d[i] > max) max = d[i];
	}
	
	printf("%d", max);
}
*/

int d[1001];
int seq[1001];

//O(N * logN) 시간복잡도 풀이 
int main() {
	
	int d_size = 0;
	int n;
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; ++i) {
		scanf("%d", &seq[i]);
	}
	
	//초기 설정 
	d[1] = seq[1];
	d_size++;
	
	for(int i=2 ; i<=n ; ++i) {
		
		if(d[d_size] < seq[i]) d[++d_size] = seq[i];
		
		else {
			for(int j=d_size ; j>=1 ; --j) {
				if(seq[i] < d[j] && seq[i] > d[j-1]) d[j] = seq[i];
			}
		}
	}
	
	printf("%d", d_size);
}
