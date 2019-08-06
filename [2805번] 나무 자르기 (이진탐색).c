#include<stdio.h>
#define ll long long

int N, M;
ll tree[1000001];
ll heigth;

int cut(ll height) {
	
	ll sum = 0;
	for(int i=0 ; i<N ; ++i) {
		ll cutTree = tree[i] - height;
		if(cutTree > 0)
			sum += cutTree;
	}
	
	if(sum >= M) return 1;
	else return 0;
}

int main() {
	
	scanf("%d%d", &N, &M);
	
	for(int i=0 ; i<N ; ++i)
		scanf("%lld", &tree[i]);
		
	ll min = 1;
	ll max = 1000000001;
	
	while(min <= max) {
		ll mid = (min + max) / 2;
		
		if(cut(mid) == 1)
			min = mid + 1;
		else
			max = mid - 1;
	}
	
	printf("%d", max);
}
