#include <bits/stdc++.h>
using namespace std;

int w;

void Input()
{
    scanf("%d", &w);
}

void Solve()
{
    if (w % 2 != 0)
    {
        printf("NO");
        return;
    }

    int a, b;
    for (int i = 2; i < w; i += 2)
        if ((w - i) % 2 == 0)
        {
            printf("YES");
            return;
        }

    printf("NO");
}

int main()
{
    Input();
    Solve();
}
