#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100000

typedef struct {
	char name[11];
	int a,b,c;
} student;

student list[MAX];

int compareStudent(void *x, void *y) {
	
	student X = *(student*)x;
	student Y = *(student*)y;
	
	if(X.a < Y.a) return 1;
	else if(X.a > Y.a) return -1;
	
	else if(X.b > Y.b) return 1;
	else if(X.b < Y.b) return -1;
	
	else if(X.c < Y.c) return 1;
	else if(X.c > Y.c) return -1;
	
	else if(strcmp(X.name, Y.name) > 0) return 1;
	else if(strcmp(X.name, Y.name) < 0) return -1;
	
	else return 0;
}

int main() {

	int N;
	scanf("%d", &N);
	
	for(int i=0 ; i<N ; ++i) {
		scanf("%s %d%d%d", list[i].name, &list[i].a, &list[i].b, &list[i].c);
	}
	
	qsort(list, N, sizeof(student), compareStudent);
	
	for(int i=0 ; i<N ; ++i) {
		printf("%s\n", list[i].name);
	}
}
