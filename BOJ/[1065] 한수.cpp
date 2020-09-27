#include <bits/stdc++.h>
using namespace std;

int X, answer;

void Input()
{
    scanf("%d", &X);
}

void Solve()
{
    if (X < 100)
        answer = X;
    else
    {
        answer = 99;
        for (int i = 101; i <= X; ++i)
        {
            int x1 = i / 100;
            int x2 = i / 10 % 10;
            int x3 = i % 10;

            if (x1 - x2 == x2 - x3)
                answer++;
        }
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
