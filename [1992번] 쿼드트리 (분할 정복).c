#include<stdio.h>
#define MAX 65

int N;
int video[MAX][MAX];

void mergeSort(int y, int x, int size) {
	
	int standard = video[y][x];
	int dSize = size / 2;
	int same = 1;
	
	for(int i=y ; i < y+size ; ++i) {
		for(int j=x ; j < x+size ; ++j) {
			if(video[i][j] != standard) {
				same = 0;
				
				printf("(");
				for(int a=0 ; a<2 ; ++a)
					for(int b=0 ; b<2 ; ++b)
						mergeSort(y + a * dSize, x + b * dSize, dSize);
				printf(")");
				
				break;
			}
		}
		if(same == 0) break;
	}
	
	if(same == 1) printf("%d", standard);
}

int main() {

	scanf("%d", &N);
	
	for(int i=1 ; i<=N ; ++i)
		for(int j=1 ; j<=N ; ++j)
			scanf("%1d", &video[i][j]);
	
	mergeSort(1,1,N);
}
