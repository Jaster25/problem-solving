#include <bits/stdc++.h>
using namespace std;

int N, test, answer;
bool isNotPrime[1001];

void Solve()
{
    for (int i = 2; i * i <= 1000; ++i)
        if (!isNotPrime[i])
            for (int j = i * 2; j <= 1000; j += i)
                isNotPrime[j] = true;

    isNotPrime[1] = 1;
}

int main()
{
    Solve();

    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &test);
        if (!isNotPrime[test])
            answer++;
    }

    printf("%d", answer);
}
