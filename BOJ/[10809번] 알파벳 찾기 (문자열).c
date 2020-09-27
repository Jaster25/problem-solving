#include<stdio.h>
#include<string.h>
int main() {
	
	char S[101];
	scanf("%s", S);
	int len = strlen(S); 
	
	int ar[26];
	memset(ar, -1, 26*sizeof(int));
	
	for(int i=0 ; i<len ; ++i) {
		if(ar[S[i] - 'a'] == -1) ar[S[i] - 'a'] = i;
	}
	
	for(int i=0 ; i<26 ; ++i) printf("%d ", ar[i]);
}
