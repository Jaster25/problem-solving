#include <bits/stdc++.h>
using namespace std;

int N, K;
int visited[100001];

void f()
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(N, 0));
    visited[N] = 0;

    while (!Q.empty())
    {
        pair<int, int> popped = Q.front();
        Q.pop();

        if (popped.first * 2 <= 100000 && visited[popped.first * 2] > visited[popped.first])
        {
            visited[popped.first * 2] = visited[popped.first];
            Q.push(make_pair(popped.first * 2, popped.second));
        }
        if (popped.first - 1 >= 0 && visited[popped.first - 1] > visited[popped.first] + 1)
        {
            visited[popped.first - 1] = visited[popped.first] + 1;
            Q.push(make_pair(popped.first - 1, popped.second + 1));
        }
        if (popped.first + 1 <= 100000 && visited[popped.first + 1] > visited[popped.first] + 1)
        {
            visited[popped.first + 1] = visited[popped.first] + 1;
            Q.push(make_pair(popped.first + 1, popped.second + 1));
        }
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    fill(&visited[0], &visited[100001], 99999999);
    f();
    printf("%d", visited[K]);
}
