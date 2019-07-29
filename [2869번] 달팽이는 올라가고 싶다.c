#include<stdio.h>

int V, A, B;
int day;

int main() {
	
	scanf("%d%d%d", &A, &B, &V);
	
	day = (V - B  - 1) / (A - B) + 1;
	
	printf("%d", day); 
}
