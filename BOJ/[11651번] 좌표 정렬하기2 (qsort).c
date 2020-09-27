#include<stdio.h>
#define MAX 100000

typedef struct {
	int x,y;
} point;

int comparePoint(void* A, void* B) {
	
	int A_x = ((point*)A)->x;
	int A_y = ((point*)A)->y;
	int B_x = ((point*)B)->x;
	int B_y = ((point*)B)->y;
	
	if( A_y > B_y ) return 1;
	else if( A_y < B_y ) return -1;
	else if( A_y == B_y && A_x > B_x) return 1;
	else if( A_y == B_y && A_x < B_x) return -1;
	else return 0;
}

int main() {
	
	int N;
	scanf("%d", &N);
	
	point array[MAX];
	
	for(int i=0 ; i<N ; ++i) {
		scanf("%d%d", &array[i].x, &array[i].y);
	}
	
	qsort(array, N, sizeof(point), comparePoint);
	
	for(int i=0 ; i<N ; ++i){
		printf("%d %d\n", array[i].x, array[i].y);
	}
}
