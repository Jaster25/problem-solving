#include <bits/stdc++.h>
using namespace std;

bool isPrime[1000001];
int test;

void SieveOfEratosthenes()
{
    isPrime[1] = false;
    memset(isPrime, 1, sizeof(isPrime));

    for (int i = 2; i * i <= 1000000; ++i)
    {
        if (isPrime[i])
            for (int j = i * i; j <= 1000000; j += i)
                isPrime[j] = false;
    }

    // * by the question
    isPrime[2] = false;
}

void check(int n)
{
    for (int i = 3; i < n; ++i)
        if (isPrime[i] && isPrime[n - i])
        {
            printf("%d = %d + %d\n", n, i, n - i);
            return;
        }
    printf("Goldbach's conjecture is wrong.\n");
}

int main()
{
    SieveOfEratosthenes();

    scanf("%d", &test);
    while (test)
    {
        check(test);
        scanf("%d", &test);
    }
}
