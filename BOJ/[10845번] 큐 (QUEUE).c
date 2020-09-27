#include<stdio.h>

int queue[10001];
int size;
int front;
int back;

void push(int x) {
	queue[++back] = x;
	size++;
}

void pop() {
	if(size == 0) printf("-1\n");
	else {
		printf("%d\n", queue[++front]);	
		size--;
	}
}

void empty() {
	if(size == 0) printf("1\n");
	else printf("0\n");
}

void qFront() {
	if(size == 0) printf("-1\n");
	else {
		printf("%d\n", queue[front + 1]);
	}
}

void qBack() {
	if(size == 0) printf("-1\n");
	else {
		printf("%d\n", queue[back]);
	}
}

int main() {
	
	int N;
	scanf("%d", &N);
	getchar();
	
	front = 0;
	back = 0;
	size = 0;
	
	for(int i=0 ; i<N ; ++i) {
		
		char str[10000];
		scanf("%s", str);
		
		if(strcmp("push", str) == 0) {
			int num;
			scanf("%d", &num);
			getchar();
			
			push(num);
		}
	
		else if(strcmp("pop", str) == 0) {
			pop();
		}
		
		else if(strcmp("size", str) == 0) {
			printf("%d\n", size);
		}
		
		else if(strcmp("empty", str) == 0) {
			empty();
		}
		
		else if(strcmp("front", str) == 0) {
			qFront();
		}
		
		else if(strcmp("back", str) == 0) {
			qBack();
		}
	}
}
