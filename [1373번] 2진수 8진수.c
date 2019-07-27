#include<stdio.h>
#include<string.h>

char binary[1000001+3] = {'0', '0', };

int main() {
	
	gets(binary + 2);
	int len = strlen(binary);
	
	int i = 0;
	while(binary[i]) binary[i++] -= '0';
	
	for(i=len%3 ; i<len ; i+=3) {
		printf("%d", binary[i]*4 + binary[i+1]*2 + binary[i+2]);
	}
}
