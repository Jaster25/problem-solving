#include<stdio.h>
#define MAX 10001
typedef enum{false, true} bool;

bool constructor[MAX];

void f(int a) {
		
	int sum = a;
	while(a) {
		sum += a % 10;
		a /= 10;
	}
	
	if(sum < MAX)
	constructor[sum] = true;
}

int main() {

	for(int i=1 ; i<MAX ; ++i) f(i);
	for(int i=1 ; i<MAX ; ++i) if(constructor[i] == false) printf("%d\n", i);

}
