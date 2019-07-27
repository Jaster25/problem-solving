#include<stdio.h>
#include<string.h>
typedef enum{false, true} bool;

char stack[1000001];
int size = 0;

void push(char ch) {

	stack[size++] = ch;
}

char pop() {

	return stack[--size];
}

char peek() {

	return stack[size - 1];
}

bool isEmpty() {
	
	if(size == 0) return true;
	else return false;
}

int main() {
	
	int N;
	scanf("%d", &N);
	getchar();	
	
	int goodWordCount = 0;

	for(int i=0 ; i<N ; ++i) {
		
		char word[100001];
		gets(word);
		int len = strlen(word);
		
		size = 0;
	
		for(int j=0 ; j<len ; ++j) {
		
			if(isEmpty()) push(word[j]);
			
			else {
				
				if(word[j] == peek()) pop();
				else push(word[j]);
			}
		}
		
		if(isEmpty()) goodWordCount++;
	}
	
	printf("%d", goodWordCount);
}
