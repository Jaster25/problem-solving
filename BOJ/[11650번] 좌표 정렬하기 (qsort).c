#include<stdio.h>
#define MAX 100000

typedef struct {
	int x,y;
} point;

int comparePoint(void* A, void* B) {

	if( ((point*)A)->x > ((point*)B)->x ) return 1;
	else if( ((point*)A)->x < ((point*)B)->x ) return -1;
	else if( ((point*)A)->x == ((point*)B)->x && ((point*)A)->y > ((point*)B)->y) return 1;
	else if( ((point*)A)->x == ((point*)B)->x && ((point*)A)->y < ((point*)B)->y) return -1;
	else return 0;
}

int main() {
	
	int N;
	scanf("%d", &N);
	
	point array[100001];
	
	for(int i=0 ; i<N ; ++i) {
		scanf("%d%d", &array[i].x, &array[i].y);
	}
	
	qsort(array, N, sizeof(point), comparePoint);
	
	for(int i=0 ; i<N ; ++i){
		printf("%d %d\n", array[i].x, array[i].y);
	}
}
