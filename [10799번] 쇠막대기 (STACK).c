#include<stdio.h>
#include<string.h>

//Stack
char stack[100000];
int size = 0;

void push(char parenthesis) {
	
	stack[size++] = parenthesis;
}

char pop() {
	return stack[--size];
}

char peek() {
	return stack[size-1];
}

int main() {
	
	int count = 0;
	char parenthesis[100001];
	gets(parenthesis);
	int len = strlen(parenthesis);
	
	for(int i=0 ; i<len ; ++i) {
		
		if(parenthesis[i] == '(') push('(');
		else {
			
			pop();
			
			if(parenthesis[i-1] == ')') count ++;
			else count += size;	//레이져로 잘린 경우 
		}
	}

	printf("%d", count);	
}
