#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

//정렬 안하고 나이 기준 반복문으로 돌리면서 출력만 해도 풀이 가능
 
typedef struct {
	int age;
	char name[101];
} member;

member list[MAX];
member sorted[MAX];

void merge(member *list, int start, int mid, int end) {
	
	int index = start;
	int first = start;
	int second = mid + 1;
	
	while(first <= mid && second <= end) {
		if(list[first].age <= list[second].age) sorted[index++] = list[first++];
		else sorted[index++] = list[second++];
	}
	
	while(first <= mid) sorted[index++] = list[first++];
	while(second <= end) sorted[index++] = list[second++];
	
	for(int i=start ; i<=end ; ++i) {
		list[i] = sorted[i];
	}
}

void mergeSort(member *list, int start, int end) {
	
	if(start >= end) return;
	
	int mid = (start + end) / 2;
	
	mergeSort(list, start, mid);
	mergeSort(list, mid + 1, end);
	merge(list, start, mid, end);
}

int main() {
	
	int N;
	scanf("%d", &N);
	

	for(int i=0 ; i<N ; ++i) {
		scanf("%d %s", &list[i].age, list[i].name);
	}
	
	mergeSort(list, 0, N-1);
	
	for(int i=0 ; i<N ; ++i) {
		printf("%d %s\n", list[i].age, list[i].name);
	}
}
