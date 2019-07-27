#include<stdio.h>
#include<string.h>
#define MAX(a,b) ( (a)>(b) ? (a) : (b) )

int d[2][100000];
int score[2][100000];
int max[100000];
int T,n;

void setting() {
	
	memset(d, 0,  100000 * 2 * sizeof(int));
	memset(score, 0,  100000 * 2 * sizeof(int));
}

int main() {
	
	scanf("%d", &T);
	
	for(int i=0 ; i<T ; ++i) {
		
		scanf("%d", &n);
		setting();
		
		for(int j=0 ; j<2 ; ++j) {
			for(int k=0 ; k<n ; ++k) {
				scanf("%d", &score[j][k]);
			}
		}
		
		//기저 조건 
		d[0][0] = score[0][0];
		d[1][0] = score[1][0];
		
		d[0][1] = d[1][0] + score[0][1];
		d[1][1] = d[0][0] + score[1][1];
		
		for(int j=2 ; j<n ; ++j) {
			
			//경우의 수 2가지 중 (한 열 건너뛰기)
			d[0][j] = MAX(d[1][j-2], d[1][j-1]) + score[0][j];
			d[1][j] = MAX(d[0][j-2], d[0][j-1]) + score[1][j];	
		}
		
		if(d[0][n-1] > d[1][n-1]) max[i] = d[0][n-1];
		else max[i] = d[1][n-1];
	}
	
	for(int i=0 ; i<T ; ++i) {
		printf("%d\n", max[i]);
	}
}
