#include <bits/stdc++.h>
using namespace std;

int N;
int ar[10001];

void Input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &ar[i]);
}

void Solve()
{
    int index = -1;
    for (int i = N - 1; i > 0; --i)
        if (ar[i - 1] < ar[i])
        {
            index = i;
            break;
        }

    if (index == -1)
        printf("-1");
    else
    {
        for (int i = N - 1; i >= index; --i)
            if (ar[index - 1] < ar[i])
            {
                swap(ar[index - 1], ar[i]);
                break;
            }

        sort(ar + index, ar + N);

        for (int i = 0; i < N; ++i)
            printf("%d ", ar[i]);
    }
}

int main()
{
    Input();
    Solve();
}
