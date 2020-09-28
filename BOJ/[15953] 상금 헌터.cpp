#include <bits/stdc++.h>
using namespace std;

int T, a, b;
int answer;

void Input()
{
    scanf("%d%d", &a, &b);
}

void Solve()
{
    answer = 0;
    if (a != 0)
    {
        if (1 <= a && a < 2)
            answer = 500;
        else if (2 <= a && a < 4)
            answer = 300;
        else if (4 <= a && a < 7)
            answer = 200;
        else if (7 <= a && a < 11)
            answer = 50;
        else if (11 <= a && a < 16)
            answer = 30;
        else if (16 <= a && a < 22)
            answer = 10;
    }
    if (b != 0)
    {
        if (1 <= b && b < 2)
            answer += 512;
        else if (2 <= b && b < 4)
            answer += 256;
        else if (4 <= b && b < 8)
            answer += 128;
        else if (8 <= b && b < 16)
            answer += 64;
        else if (16 <= b && b < 32)
            answer += 32;
    }

    printf("%d\n", answer * 10000);
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        Input();
        Solve();
    }
}
