#include <bits/stdc++.h>
using namespace std;

int N, sumMax;
int A[9], ar[9];
bool visited[9];

void Input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
}

int calculate()
{
    int result = 0;
    for (int i = 0; i < N - 1; ++i)
        result += abs(ar[i] - ar[i + 1]);
    return result;
}

void dfs(int cnt)
{
    if (cnt == N)
    {
        int sumA = calculate();
        sumMax = max(sumA, sumMax);
        return;
    }

    for (int i = 0; i < N; ++i)
        if (!visited[i])
        {
            visited[i] = true;
            ar[cnt] = A[i];
            dfs(cnt + 1);
            visited[i] = false;
        }
}

void Solve()
{
    for (int i = 0; i < N; ++i)
    {
        visited[i] = true;
        ar[0] = A[i];
        dfs(1);
        visited[i] = false;
    }

    printf("%d", sumMax);
}

int main()
{
    Input();
    Solve();
}
