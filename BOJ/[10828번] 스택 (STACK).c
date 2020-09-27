#include<stdio.h>
#include<string.h>

int stack[10001];
int size;

void push(int x) {
	stack[size++] = x;
}

int pop() {
	if(size == 0) printf("-1\n");
	else printf("%d\n", stack[--size]);
}

void top() {
	if(size == 0) printf("-1\n");
	else printf("%d\n", stack[size - 1]);
}

void empty() {
	if(size ==0 ) printf("1\n");
	else printf("0\n");
}

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	
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
		
		else if(strcmp("top", str) == 0) {
			top();
		}
	}
}
