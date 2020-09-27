#include <bits/stdc++.h>
using namespace std;

int N;
int cnt3, cnt5;

void Input()
{
    scanf("%d", &N);
}

void Solve()
{
    cnt5 = N / 5;
    N %= 5;
    cnt3 += N / 3;
    N %= 3;

    while (N > 0 && cnt5 > 0)
    {
        N += 5;
        cnt5--;
        cnt3 += N / 3;
        N %= 3;

        if (N == 0)
            break;
    }

    if (N == 0)
        printf("%d", cnt5 + cnt3);
    else
        printf("-1");
}

int main()
{
    Input();
    Solve();
}