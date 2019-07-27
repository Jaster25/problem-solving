#include<stdio.h>
#include<string.h>
#include<math.h>

char N[100000000];
int B;

char stack[100001];
int count;
int len;
int size;
long long sum;

void push(char a) {
	stack[size++] = a;
}

void pop() {
	
	char temp = stack[--size];
	long long changed;
	
	if(temp >= 'A' && temp <= 'Z') {
		changed = (temp - 'A' + 10) * pow(B, count);
	}
	else {
		changed = (temp - '0') * pow(B, count);
	}
	
	sum += changed;
}

int isEmpty() {
	if(size == 0) return 1;
	else return 0;
}

int main() {
	
	scanf("%s%d", &N, &B);
	count = 0;
	size = 0;
	
	sum = 0;
	len = strlen(N);
		
	for(int i=0 ; i<len ; ++i) {
		push(N[i]);
	}
	
	while( !isEmpty() ) {
		pop();
		count++;
	}
	
	printf("%lld", sum);
}
