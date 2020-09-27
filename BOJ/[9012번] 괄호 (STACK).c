#include<stdio.h>
typedef enum {false, true} bool;

//Stack
char stack[1000000];
int size = 0;

void push(char parenthesis) {
	
	stack[size++] = parenthesis;
}

char pop() {
	return stack[--size];
}

bool isEmpty() {
	
	if(size==0) return true;
	else return false;
}

int main() {
	
	int N;
	scanf("%d", &N);
	getchar();
	
	
	char parenthesis[51];
	
	for(int i=0 ; i<N ; ++i) {
		
		int check = 1;
		size = 0;
		gets(parenthesis);
			
		for(int j=0 ; j<strlen(parenthesis) ; ++j) {
			
			if(parenthesis[j] == '(') {
				push('(');
			}
		
			else if(parenthesis[j] == ')') {
				char temp = pop();
				if(temp != '(') {
					check = 0;
					break;
				}
			}
		}
		
		if(check == 1 && isEmpty()) printf("YES\n");
		else printf("NO\n");
	}
}
