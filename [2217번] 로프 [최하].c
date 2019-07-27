#include<stdio.h>
void quickSort(int *array, int start, int end);

int main() {
	
	int N;
	scanf("%d", &N);
	
	int rope[100000];
		
	int maxWeight = 0;	//들어올릴 수 있는 물체의 최대 중량 
	int weight = 0;	//현재의 들어올릴 수 있는 물체의 중량 
	int k = N;	//사용할 로프 개수	
	
	for(int i=0 ; i<N ; i++) {
		scanf("%d", &rope[i]);
	}
	
	//내림차순으로 정렬해주기 
	quickSort(rope, 0, N-1);
	
	//뒤에서 부터 하나씩 빼면서 비교하기 
	for(int i=N-1 ; i>=0 ; i--) {
		
		weight = (rope[i] * (i+1));
		
		if(weight > maxWeight) {
			maxWeight = weight;
		}	
	} 
		
	printf("%d", maxWeight);
}


void quickSort(int *array, int start, int end) {
	
	if(start >= end) return;
	
	int pivot = array[start];
	int toRight = start + 1;
	int toLeft = end;
	
	
	while(toRight <= toLeft) {		//엇갈릴 때까지 반복 
		
		while(array[toRight] >= pivot) {	//피벗보다 큰 값을 찾아서 
			toRight++;
		}
		
		while(array[toLeft] <= pivot && toLeft>start) {	//피벗보다 작은 값을 찾아서
			toLeft--;
		}
		
		
		if(toRight > toLeft) {		//엇갈린 상태면 피벗 교체
			int temp = array[start];	
			array[start] = array[toLeft];
			array[toLeft] = temp;
		}
		
		else {						//아닐 경우 좌우 교체 
			int temp = array[toLeft];	
			array[toLeft] = array[toRight];
			array[toRight] = temp;
		}
		
	}
	
	quickSort(array, start, toLeft-1);
	quickSort(array, toLeft+1, end);
}
