#include<stdio.h>
#include<stdlib.h>
#define MAX 51

typedef struct Node {
	struct Node *child[MAX];
	int childNum;
	int data;
	int pData;
} Node;

Node *createNode(int PDATA, int DATA) {
	Node *newNode = (Node*) malloc (sizeof(Node));
	
	newNode->childNum = 0;
	newNode->pData = PDATA;
	newNode->data = DATA;

	return newNode;	
}

Node *node[MAX];
Node *root;

//재귀 전위순회하며 확인 
int leafCount = 0;
void checkLeafNode(Node *_node) {
	
	if(_node->childNum == 0) {
		leafCount++;
		return;	
	}
	
	for(int i=1 ; i<=_node->childNum ; ++i) {
		checkLeafNode(_node->child[i]);
	}
}

void deleteNode(int Num) {
	
	Node *p = node[node[Num]->pData];
	
	int del;
	for(int i=1 ; i<=p->childNum ; ++i) {
		if(p->child[i]->data == Num) del = i;
	}
	
	for(int i=del ; i<p->childNum ; ++i) {
		p->child[i] = p->child[i+1];
	}
	
	p->childNum--;
}

int main() {

	int N;
	scanf("%d", &N);
	
	//트리 생성 
	for(int i=0 ; i<N ; ++i) {
		int temp;
		scanf("%d", &temp);
		
		node[i] = createNode(temp, i);
		if(temp == -1) root = node[i];
	}
	
	for(int i=0 ; i<N ; ++i) {
		if(node[i]->pData != -1) {
			Node *p = node[node[i]->pData];
			p->child[++(p->childNum)] = node[i];
		}
	}
	
	int deleteNum;
	scanf("%d", &deleteNum);
	
	//루트 노드 제거시 0 출력후 종료
	if(node[deleteNum] == root) {
		printf("0");
		return -1;
	}
	
	deleteNode(deleteNum);
	
	checkLeafNode(root);
	
	printf("%d", leafCount);
}
