#include<stdio.h>
#include<string.h>

int main() {
	char S[101];
	int len = strlen(gets(S));
	
	for(int i=0 ; i<len ; ++i) {
		if(S[i]>='a' && S[i]<='z'-13) S[i] += 13;
		else if(S[i]>='a'+13 && S[i]<='z') S[i] -= 13;

		else if(S[i]>='A' && S[i]<='Z'-13) S[i] += 13;
		else if(S[i]>='A'+13 && S[i]<='Z') S[i] -= 13;
	}
	
	printf("%s", S);
}
