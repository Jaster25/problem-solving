#include<stdio.h>
#define MIN(a,b) (a<b ? a : b)

//nCm = n! / (m!(n-m)!)
// 각각을 A, B, C라고 칭한다

int N, M;
int A,B,C;

int count2;
int A2cnt = 0;
int B2cnt = 0;
int C2cnt = 0;

int count5;
int A5cnt = 0;
int B5cnt = 0;
int C5cnt = 0;

int main() {
	
	scanf("%d%d", &N, &M);
	
	A = N;
	B = M;
	C = N - M;
	
	//2의 개수
	while(A >= 2) {
		A /= 2;
		A2cnt += A;
	}
	while(B >= 2) {
		B /= 2;
		B2cnt += B;
	}
	while(C >= 2) {
		C /= 2;
		C2cnt += C;
	}
	
	A = N;
	B = M;
	C = N - M;
	
	//5의 개수
	while(A >= 5) {
		A /= 5;
		A5cnt += A;
	}
	while(B >= 5) {
		B /= 5;
		B5cnt += B;
	}
	while(C >= 5) {
		C /= 5;
		C5cnt += C;
	}
	
	count2 = A2cnt - B2cnt - C2cnt;
	count5 = A5cnt - B5cnt - C5cnt;
	
	printf("%d", MIN(count2, count5));
}
