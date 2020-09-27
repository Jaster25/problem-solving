#include <bits/stdc++.h>
using namespace std;

int n, m, a;

void Input()
{
    scanf("%d%d%d", &n, &m, &a);
}

void Solve()
{
    long long int row, col;
    col = n / a;
    if (n % a != 0)
        col++;
    row = m / a;
    if (m % a != 0)
        row++;

    printf("%lld", col * row);
}

int main()
{
    Input();
    Solve();
}
