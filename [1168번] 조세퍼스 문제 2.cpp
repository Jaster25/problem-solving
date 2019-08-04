#include<iostream>
#include<vector>
using namespace std;

int N, K;

vector<int> permutation;
vector<int> answer;

int main() {
	
	scanf("%d%d", &N, &K);
	
	for(int i=1 ; i<=N ; ++i) {
		permutation.push_back(i);
	}
	
	int index = 0;
	int remain = N;
	
	while(!permutation.empty()) {
		index = (index + K - 1) % permutation.size();
		answer.push_back(permutation[index]);
		permutation.erase(permutation.begin() + index);
	}
	
	printf("<%d", answer[0]);
	for(int i=1 ; i<answer.size() ; ++i) {
		printf(", %d", answer[i]);
	}
	printf(">");
}
