#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	char data;
} Node;

Node *root;
Node *node[26];
char temp[26][2];

Node* createNode(char x, char L, char R) {
	Node *newNode = (Node*) malloc (sizeof(Node));
	
	newNode->data = x;
	
	if(L == '.') newNode->left = NULL;
	else newNode->left = node[L-'A'];
	
	if(R == '.') newNode->right = NULL;
	else newNode->right = node[R-'A'];
	
	return newNode;
}

void preOrder(Node *horse) {
	if(horse == NULL) return;
	
	printf("%c", horse->data);
	preOrder(horse->left);
	preOrder(horse->right);
}

void inOrder(Node *horse) {
	if(horse == NULL) return;
	
	inOrder(horse->left);
	printf("%c", horse->data);
	inOrder(horse->right);
}

void postOrder(Node *horse) {
	if(horse == NULL) return;

	postOrder(horse->left);
	postOrder(horse->right);
	printf("%c", horse->data);
}

int main() {
	
	int N;
	scanf("%d", &N);
	getchar();
	
	for(int i=0 ; i<N ; ++i) {
		char a;
		scanf("%c ", &a);
		scanf("%c %c", &temp[a-'A'][0], &temp[a-'A'][1]);
		getchar();
	}
	
	for(int i=N-1 ; i>=0 ; --i) {
		node[i] = createNode(i + 'A', temp[i][0], temp[i][1]);
	}
	
	root = node[0];
	
	preOrder(root);
		printf("\n");
	inOrder(root);
		printf("\n");
	postOrder(root);
}

