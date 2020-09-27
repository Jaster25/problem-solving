#include<stdio.h>
#include<string.h>

int main() {
	
	int data[26] = {0,};
	char str[101];
	gets(str);
	int len = strlen(str);
	
	for(int i=0 ; i<len ; ++i) {
		data[str[i] - 'a']++;
	}
	
	for(int i=0 ; i<26 ; ++i) printf("%d ", data[i]);
}
