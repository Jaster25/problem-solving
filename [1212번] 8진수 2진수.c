#include<stdio.h>

int main() {
	
	int check = 0;
	char a;
	
	while((a = getchar()) != '\n') {
		
		if(check == 0 && a == '0') continue;
		
		else if(check == 0 && a != '0') {
			switch (a) {
				case '1' :
					printf("1");
					break;
				case '2' :
					printf("10");
					break;
				case '3' :
					printf("11");
					break;
				case '4' :
					printf("100");
					break;
				case '5' :
					printf("101");
					break;
				case '6' :
					printf("110");
					break;
				case '7' :
					printf("111");
					break;
			}
			
			check = 1;
		}
		
		else {
			switch (a) {
				case '0' :
					printf("000");
					break;
				case '1' :
					printf("001");
					break;
				case '2' :
					printf("010");
					break;
				case '3' :
					printf("011");
					break;
				case '4' :
					printf("100");
					break;
				case '5' :
					printf("101");
					break;
				case '6' :
					printf("110");
					break;
				case '7' :
					printf("111");
					break;
			}
		}
	}
	
	if(check == 0) printf("0");
}
