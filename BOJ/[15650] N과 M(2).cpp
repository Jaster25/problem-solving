#include <bits/stdc++.h>
using namespace std;

int N, M;
bool ar[9];

void dfs(int index, int count)
{
    if (count == M)
    {
        for (int i = 1; i <= N; ++i)
            if (ar[i])
                printf("%d ", i);
        printf("\n");
        return;
    }
	
    for (int i = index + 1; i <= N; ++i)
    {
        ar[i] = true;
        dfs(i, count + 1);
        ar[i] = false;
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    dfs(0, 0);
}
