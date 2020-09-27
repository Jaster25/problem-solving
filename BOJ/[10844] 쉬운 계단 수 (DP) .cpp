#include <bits/stdc++.h>
using namespace std;

int N, answer;
int d[101][10];

void Input()
{
    scanf("%d", &N);
}

int f(int index1, int index2)
{
    if (index1 == 1 || d[index1][index2] != 0)
        return d[index1][index2];

    switch (index2)
    {
    case 0:
        return d[index1][index2] = f(index1 - 1, 1);
    case 9:
        return d[index1][index2] = f(index1 - 1, 8);
    default:
        return d[index1][index2] = (f(index1 - 1, index2 + 1) + f(index1 - 1, index2 - 1)) % 1000000000;
    }
}

void Solve()
{
    for (int i = 1; i <= 9; ++i)
        d[1][i] = 1;

    for (int i = 0; i <= 9; ++i)
        answer = (answer + f(N, i)) % 1000000000;

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}