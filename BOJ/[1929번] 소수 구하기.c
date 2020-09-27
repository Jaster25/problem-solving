#include<stdio.h>
#include<stdbool.h>

int N, M;
bool noPrime[1000001];

int main() {
	
	scanf("%d%d", &N, &M);

	noPrime[1] = true;	
	for(int i = 2 ; i*i <= M ; ++i) {

		if(noPrime[i])
			continue;
			
		for(int j = i+i ; j <= M ; j += i)
			noPrime[j] = true;
	}
	
	for(int i = N ; i <= M ; ++i)
		if(noPrime[i] == false)
			printf("%d\n", i);	
}
