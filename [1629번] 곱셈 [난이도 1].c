#include<stdio.h>

long long int function(long long int A, long long int B, long long int C) {
	
	if (B == 0)
        return 1;
        
    else if (B == 1)
        return A;
        
    
    //B이 홀수일 때 
	if (B % 2)
        return function(A, B - 1, C) * A;
        
    long long int half = function(A, B / 2, C);
    half %= C;
    
    return (half * half) % C;

}


int main() {
	
	long long int A, B, C;
	scanf("%lld%lld%lld", &A, &B, &C);
	
	printf("%lld", function(A, B, C) % C);
	
}
