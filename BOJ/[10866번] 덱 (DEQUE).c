#include<stdio.h>

int deque[30001];
int size;
int front;
int back;

//이 경우 터질 수 있으니 시작점을 15000으로 설정 
void push_front(int x) {
	if(size == 0) {
		deque[++back] = x;
	}
	
	else {
		deque[front--] = x;
	}
	
	size++;	
}

void push_back(int x) {

	deque[++back] = x;
	size++;	
}

void pop_front() {
	if(size == 0) printf("-1\n");
	
	else {
		printf("%d\n", deque[++front]);	
		size--;
	}
}

void pop_back() {
	if(size == 0) printf("-1\n");
	
	else {
		printf("%d\n", deque[back--]);	
		size--;
	}
}

void empty() {
	if(size == 0) printf("1\n");
	else printf("0\n");
}

void Front() {
	if(size == 0) printf("-1\n");
	else {
		printf("%d\n", deque[front + 1]);
	}
}

void Back() {
	if(size == 0) printf("-1\n");
	else {
		printf("%d\n", deque[back]);
	}
}

int main() {
	
	int N;
	scanf("%d", &N);
	getchar();
	
	front = 15000;
	back = 15000;
	size = 0;
	
	for(int i=0 ; i<N ; ++i) {
		
		char str[10000];
		scanf("%s", str);
		
		if(strcmp("push_front", str) == 0) {
			int num;
			scanf("%d", &num);
			getchar();
			
			push_front(num);
		}
		
		else if(strcmp("push_back", str) == 0) {
			int num;
			scanf("%d", &num);
			getchar();
			
			push_back(num);
		}
	
		else if(strcmp("pop_front", str) == 0) {
			pop_front();
		}
		
		else if(strcmp("pop_back", str) == 0) {
			pop_back();
		}
		
		else if(strcmp("size", str) == 0) {
			printf("%d\n", size);
		}
		
		else if(strcmp("empty", str) == 0) {
			empty();
		}
		
		else if(strcmp("front", str) == 0) {
			Front();
		}
		
		else if(strcmp("back", str) == 0) {
			Back();
		}
	}
}
