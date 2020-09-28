#include <bits/stdc++.h>
using namespace std;

int N, M;
int answer;
bool visited[10001];

void Input()
{
    scanf("%d%d", &N, &M);
}

void bfs(int num)
{

    queue<pair<int, int>> Q;
    Q.push(make_pair(num, 0));

    while (!Q.empty())
    {
        int n = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();

        if (n == M)
        {
            answer = cnt;
            return;
        }

        // * red button
        if (n * 2 <= 10000 && !visited[n * 2])
        {
            visited[n * 2] = true;
            Q.push(make_pair(n * 2, cnt + 1));
        }
        // * blue button
        if (n - 1 >= 1 && !visited[n - 1])
        {
            visited[n - 1] = true;
            Q.push(make_pair(n - 1, cnt + 1));
        }
    }
}

void Solve()
{
    visited[N] = true;
    bfs(N);
    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
