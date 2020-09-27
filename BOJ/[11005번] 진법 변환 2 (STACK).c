#include<stdio.h>

int N, B;
	
int stack[100001];
int size;

void push(int a) {
	stack[size++] = a;
}

char pop() {
	
	int temp = stack[--size];
	char changed;
	
	if(temp >= 10) {
		changed = 'A' + temp - 10;
	}
	else {
		changed = '0' + temp;
	}
	
	return changed;
}

int isEmpty() {
	if(size == 0) return 1;
	else return 0;
}

int main() {
	
	size = 0;
	scanf("%d%d", &N, &B);
	
	while(N >= B) {
		push(N % B);
		N /= B;
	}
	push(N);
	
	while( !isEmpty() ) {
		printf("%c", pop());
	}
}
