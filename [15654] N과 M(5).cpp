#include <bits/stdc++.h>
using namespace std;

int N, M;
int ar[9];
bool check[9];
vector<int> sequence;

void dfs(int count)
{
	if (count == M)
	{
		for (auto i : sequence)
			printf("%d ", i);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			sequence.push_back(ar[i]);
			dfs(count + 1);
			sequence.pop_back();
			check[i] = false;
		}
	}
}

int main()
{

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", &ar[i]);

	sort(&ar[0], &ar[0] + N);

	dfs(0);
}