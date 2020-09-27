#include <bits/stdc++.h>
using namespace std;

int N, K;
int thing[101][2];
int dp[100001];

void knapsack()
{
    for (int i = 0; i < N; ++i)
        for (int j = K; j - thing[i][0] >= 0; j--)
            dp[j] = max(dp[j], dp[j - thing[i][0]] + thing[i][1]);
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i)
        scanf("%d%d", &thing[i][0], &thing[i][1]);

    knapsack();

    printf("%d", dp[K]);
}
