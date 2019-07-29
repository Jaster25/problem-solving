#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node *next;
	struct Node *prev;
	int num;
	
} Node;

Node *list;
Node *head;

Node* createNode(int num) {
	Node *newNode = (Node*) malloc (sizeof(Node));
	newNode->num = num;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

void init(int num) {
	
	int index = 1;
	while(index <= num) {
		
		Node *newNode = createNode(index);
		
		//리스트가 직접 움직임 
		if(index == 1) {
			list = newNode;
			head = list;
		}
		else {
			list->next = newNode;
			newNode->prev = list;
			
			list = list->next; 
		}

		index++;
	}
	
	//환형 구조 
	head->prev = list;
	list->next = head;
}

void movePop(int k) {
	
	for(int i=0 ; i<k ; ++i) {
		list = list->next;
	}
	
	printf("%d, ", list->num);
	
	list->next->prev = list->prev;
	list->prev->next = list->next;
}

int main() {
	
	int N,K;
	scanf("%d%d", &N, &K);
	
	int size = N;
	
	init(N);
	
	printf("<");
	for(int i=1 ; i<N ; ++i) {
		movePop(K);
	}
	
	printf("%d>", list->next->num);
}
