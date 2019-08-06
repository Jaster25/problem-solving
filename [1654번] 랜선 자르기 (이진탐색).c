#include<stdio.h>
#include<stdlib.h>
#define ll long long

int K, N;
int line[10001];

int compare(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int cut(ll length) {
	
	int count = 0;

	for(int i=0 ; i<K ; ++i)
		count += line[i] / length;
	
	if(count >= N) return 1;
	else return 0;
}

int main() {
	
	scanf("%d%d", &K, &N);
	
	for(int i=0 ; i<K ; ++i)
		scanf("%d", &line[i]);
	
	qsort(line, K, sizeof(int), compare);
	
	ll left = 1;
	ll right = line[K-1];
	
	while(left <= right) {
		
		ll mid = (left + right) / 2;

		if(cut(mid) == 1)
			left = mid + 1;
		else
			right = mid - 1;
	}
	
	printf("%lld", right);
}
