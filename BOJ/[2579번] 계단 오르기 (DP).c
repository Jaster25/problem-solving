//접근 방식이 뒤에서부터 + 저장소 d[]의 2차원 배열화 
//매크로 삼항연산자 괄호 주의
//#define MAX(a,b) a > b ? a : b 이거 안됨 연산자의 우선순위때문 

#include<stdio.h>
#define MAX(a,b) (a>b ? a : b)

//[0]은 이전에 2칸 올라온 경우, [1]은 1칸 올라온 경우 
int d[301][2];
int score[301];

void dp(int i) {
	
	d[i][0] = MAX(d[i-2][0], d[i-2][1]) + score[i];
	d[i][1] = d[i-1][0] + score[i];	//문제 조건 때문에 이전에 2칸 오르는 것이 강제됨
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	for(int i=1 ; i<=n ; i++) scanf("%d", &score[i]);
	d[1][0] = d[1][1] = score[1];

	for(int i=2 ; i<=n ; i++) dp(i);
	
	printf("%d", MAX(d[n][0], d[n][1]));
}
