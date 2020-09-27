#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compareStr(void* a, void* b) {
	return strcmp((char*)a, (char*)b);
}

int main() {
	
	char S[1001] = {0,};
	int len = strlen(gets(S));

	char sub[1001][1001];
	
	for(int i=0 ; i<len ; ++i) {
		strcpy(sub[i], &S[i]);
	}
	
	qsort(sub, len, sizeof(S), compareStr);

	for(int i=0 ; i<len ; ++i) {
		printf("%s\n", sub[i]);
	}
}
