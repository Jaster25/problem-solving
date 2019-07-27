#include<stdio.h>
#include<string.h>

int main() {
	
	char str[101];
	while(gets(str)) {
		
		int a = 0;
		int A = 0;
		int num = 0;
		int blank = 0;
		
		int len = strlen(str);
		
		for(int j=0 ; j<len ; ++j) {
			if(str[j] >= 'a' && str[j] <= 'z') a++;
			else if(str[j] >= 'A' && str[j] <= 'Z') A++;
			else if(str[j] == ' ') blank++;
			else num ++;
		}
		
		printf("%d %d %d %d\n", a, A, num, blank);
	}
} 
