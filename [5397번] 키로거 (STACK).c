#include<stdio.h>

char stack1[1000001], stack2[1000001];
int size1, size2;

//1의 Top에 추가 
void add(char ch) {

	stack1[++size1] = ch;
}

//1 <- 2 '>'일 때
void push() {
	if(size2 > 0)
		stack1[++size1] = stack2[size2--];
}

//1 -> 2 '<'일 때
void pop() {
	if(size1 > 0)
		stack2[++size2] = stack1[size1--];
}

//Top 제거 
void del() {
	if(size1 > 0)
		stack1[size1--];
}

void print() {
	
	//stack1 print
	for(int i=1 ; i<=size1 ; ++i)
		printf("%c", stack1[i]);

	//stack2 print
	for(int i=size2 ; i>=1 ; --i)
		printf("%c", stack2[i]);
	
	printf("\n");
} 


void reset() {
	size1 = size2 = 0;
}

int main() {
	
	int L;
	scanf("%d", &L);
		getchar();
	
	while(L--) {
		
		reset();
		
		char ch;
		while((ch = getchar()) != '\n') {
			
			switch (ch) {
				
				case '<':
					pop();
					break;
				
				case '>':
					push();
					break;
					
				case '-':
					del();
					break;
					
				default :
					add(ch);
					break;
			}
		}

		print();
	}	
}
