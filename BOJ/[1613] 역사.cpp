#include <bits/stdc++.h>
using namespace std;

int N, K;
int a, b, s;
int sequence[401][401];

int main()
{
    scanf("%d%d", &N, &K);

    for (int i = 0; i < K; ++i)
    {
        scanf("%d%d", &a, &b);
        sequence[a][b] = -1;
        sequence[b][a] = 1;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (sequence[i][j] == 0)
                {
                    if (sequence[i][k] == 1 && sequence[k][j] == 1)
                        sequence[i][j] = 1;
                    else if (sequence[i][k] == -1 && sequence[k][j] == -1)
                        sequence[i][j] = -1;
                }
            }
        }
    }

    scanf("%d", &s);
    while (s--)
    {
        scanf("%d%d", &a, &b);
        printf("%d\n", sequence[a][b]);
    }
}