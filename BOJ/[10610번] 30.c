#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char num[100000000];

int compare(void* a, void* b) {
	return (*(char*)a < *(char*)b ) * 2 - 1;
}

int main() {

	int len = strlen(gets(num));
	
	int sum = 0;
	for(int i=0 ; i<len ; ++i) {
		sum += num[i] - '0';
	}
	
	qsort(num, len, sizeof(char), compare);
		
	if(num[len-1] != '0' || (sum) % 3 != 0) printf("-1");
	else printf("%s", num);	
}
