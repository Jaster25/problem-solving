#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll A, B, C;

ll f(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return A;
    if (n % 2 == 0)
    {
        ll half = f(n / 2);
        return half * half % C;
    }
    return f(n - 1) * A % C;
}

int main()
{
    scanf("%lld%lld%lld", &A, &B, &C);

    printf("%lld", f(B) % C);
}
