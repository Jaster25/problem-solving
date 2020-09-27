#include<stdio.h>
#define MAX 50

int caseNumber;
int lotto[MAX];
int save[7];
int count;

void dfs(int count) {
	
	if(count == 6) {
		for(int i=1 ; i<=6 ; ++i) {
			printf("%d ", save[i]);
		}
		printf("\n");
		return;
	}
	
	else {
		for(int i=1 ; i<=caseNumber ; ++i) {
			if(save[count] < lotto[i]) {
				save[++count] = lotto[i];
				dfs(count--);
			}
		}
	}
}

int main() {
	
	scanf("%d", &caseNumber);
	while(caseNumber != 0) {
		
		count = 0;
		
		for(int i=1;  i<=caseNumber ; ++i) {
			scanf("%d", &lotto[i]);
		}
		
		save[0] = 0;
		dfs(0);
		printf("\n");
		
		scanf("%d", &caseNumber);
	}
} 
