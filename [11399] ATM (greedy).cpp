#include <bits/stdc++.h>
using namespace std;

int N, P[1001], wait[1001];
int answer;

void Input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &P[i]);
}

void Solve()
{
    sort(&P[0], &P[N]);

    wait[0] = P[0];
    for (int i = 1; i < N; ++i)
        wait[i] = wait[i - 1] + P[i];
    for (int i = 0; i < N; ++i)
        answer += wait[i];

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
