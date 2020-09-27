#include<stdio.h>
#include<stdlib.h>

char str[12][2];

int compare(void* a, void* b) {
	return strcmp((char*)a, (char*)b) * -1;
}

int main() {
	
	int index = 0;
	char temp;
	while((temp = getchar()) != '\n') {
		str[index][0] = temp;
		str[index][1] = NULL;
		index++;
	}
	
	qsort(str, index, sizeof(str[1]), compare);
	
	for(int i=0 ; i<index ; ++i) {
		printf("%c", str[i][0]);
	}
}
