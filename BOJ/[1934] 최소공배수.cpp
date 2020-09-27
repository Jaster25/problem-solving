#include <bits/stdc++.h>
using namespace std;

int A, B;

void Input()
{
    scanf("%d%d", &A, &B);
}

int GCD(int a, int b)
{
    if (a < b)
        return GCD(b, a);

    int r = a % b;
    if (r == 0)
        return b;
    return GCD(b, r);
}

int GCM(int a, int b)
{
    return a * b / GCD(a, b);
}

void Solve()
{
    printf("%d\n", GCM(A, B));
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        Input();
        Solve();
    }
}
