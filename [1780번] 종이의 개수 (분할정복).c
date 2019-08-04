#include<stdio.h>
#define MAX 2190

int N;
int paper[MAX][MAX];

//-1, 0, 1 ¼ø¼­ -> index : 0, 1, 2 
int cnt[3];

void mergeSort(int y, int x, int size) {
	
	int standard = paper[y][x];
	
	for(int i=y ; i < y + size ; ++i) {
		for(int j=x ; j < x + size ; ++j) {
			if(paper[i][j] != standard) {
				
				int dSize = size / 3;
				for(int a=0 ; a<3 ; ++a) {
					for(int b=0 ; b<3 ; ++b) {
						mergeSort(y + a * dSize, x + b * dSize, dSize);
					}
				}
				
				return;
			}
		}
	}

	cnt[standard+1]++;
}

int main() {
	
	scanf("%d", &N);
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			scanf("%d", &paper[i][j]);
			
	mergeSort(1, 1, N);
	
	printf("%d\n%d\n%d", cnt[0], cnt[1], cnt[2]);
}
