#include <bits/stdc++.h>
using namespace std;

int N, M;

void Input()
{
    scanf("%d%d", &N, &M);
}

// * Greatest Common Divisor
int GCD(int a, int b)
{
    if (a < b)
        return GCD(b, a);

    int r = a % b;
    if (r == 0)
        return b;
    return GCD(b, r);
}

// * Greatest Common Multiple
int GCM(int a, int b)
{
    return a * b / GCD(a, b);
}

void Solve()
{
    printf("%d\n%d", GCD(N, M), GCM(N, M));
}

int main()
{
    Input();
    Solve();
}
