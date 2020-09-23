#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100001];
int parent[100001];

void Input()
{
    scanf("%d%d", &N, &K);
}

void Solve()
{
    queue<pair<int, int>> Q;
    visited[N] = true;
    Q.push(make_pair(N, 0));

    while (!Q.empty())
    {
        int now = Q.front().first;
        int time = Q.front().second;
        Q.pop();

        if (now == K)
        {
            printf("%d\n", time);

            stack<int> answer;
            while (now != N)
            {
                answer.push(now);
                now = parent[now];
            }
            answer.push(now);

            while (!answer.empty())
            {
                printf("%d ", answer.top());
                answer.pop();
            }

            return;
        }

        for (int nnow : {now - 1, now + 1, now * 2})
            if (nnow >= 0 && nnow <= 100000)
                if (!visited[nnow])
                {
                    visited[nnow] = true;
                    parent[nnow] = now;
                    Q.push(make_pair(nnow, time + 1));
                }
    }
}

int main()
{
    Input();
    Solve();
}
