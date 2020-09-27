#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20001

char sentence[MAX][51];

int compareSentence(void* A, void* B) {
	
	if(strlen((char*)A) > strlen((char*)B)) return 1;
	if(strlen((char*)A) < strlen((char*)B)) return -1;
	return strcmp((char*)A, (char*)B);
}

int main() {

	int N;
	scanf("%d", &N);
	getchar(); 
	
	for(int i=0 ; i<N ; ++i) {
		gets(sentence[i]);
	}
	
	qsort(sentence, N, sizeof(sentence[0]), compareSentence);
	 
	for(int i=0 ; i<N ; ++i) {
		if(i != 0 && strcmp(sentence[i], sentence[i-1]) == 0) continue;
		printf("%s\n", sentence[i]);
	}
}
