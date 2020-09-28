#include <bits/stdc++.h>
using namespace std;

int N, temp;
priority_queue<int> pq;

void Solve()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            scanf("%d", &temp);
            pq.push(-temp);
            if (pq.size() > N)
                pq.pop();
        }

    printf("%d", -pq.top());
}

int main()
{
    Solve();
}
