#include<stdio.h>
#include<string.h>

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
	
	//1->2
	while(size1)
		pop();

	//stack2 print
	for(int i=size2 ; i>=1 ; --i)
		printf("%c", stack2[i]);
	
	printf("\n");
} 

void reset() {
	size1 = size2 = 0;
}

int main() {
	
	char str[100001];
	gets(str);
	
	int len = strlen(str);
	for(int i=0 ; i<len ; ++i)
		add(str[i]);
	
	int L;
	scanf("%d", &L);
		getchar();
	
	while(L--) {
		
		char order, ch;
		scanf("%c", &order);
			getchar();
		
		switch (order) {
				
				case 'L':
					pop();
					break;
				
				case 'D':
					push();
					break;
					
				case 'B':
					del();
					break;
			
				case 'P':
					scanf("%c", &ch);
						getchar();
					add(ch);
					break;
			}
		}
		
	print();
}
