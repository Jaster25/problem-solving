#include <bits/stdc++.h>
using namespace std;

int N, K;

void Input()
{
    scanf("%d%d", &N, &K);
}

void Solve()
{
    int r = 0;
    for (int i = 1; i <= N; ++i)
        r = (r + K) % i;
    printf("%d", r + 1);
}

int main()
{
    Input();
    Solve();
}
