#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<int> ar;

void Input()
{
    int temp;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &temp);
        ar.push_back(temp);
    }
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

void Solve()
{
    int sumGCD = 0;
    for (int i = 0; i < ar.size() - 1; ++i)
        for (int j = i + 1; j < ar.size(); ++j)
            sumGCD += GCD(ar[i], ar[j]);

    printf("%d\n", sumGCD);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ar.clear();
        Input();
        Solve();
    }
}
