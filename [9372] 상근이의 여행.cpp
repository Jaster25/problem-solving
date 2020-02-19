#include <bits/stdc++.h>
using namespace std;

int N, M;

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &N, &M);
        int a, b;
        for (int i = 0; i < M; ++i)
            scanf("%d%d", &a, &b);
        printf("%d\n", N - 1);
    }
}