#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100001];

int f(int start)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(start, 0));

    while (!Q.empty())
    {
        pair<int, int> popped = Q.front();
        Q.pop();

        if (popped.first == K)
            return popped.second;

        if (popped.first * 2 <= 100000 && !visited[popped.first * 2])
        {
            Q.push(make_pair(popped.first * 2, popped.second + 1));
            visited[popped.first * 2] = true;
        }
        if (popped.first + 1 <= 100000 && !visited[popped.first + 1])
        {
            Q.push(make_pair(popped.first + 1, popped.second + 1));
            visited[popped.first + 1] = true;
        }
        if (popped.first - 1 >= 0 && !visited[popped.first - 1])
        {
            Q.push(make_pair(popped.first - 1, popped.second + 1));
            visited[popped.first - 1] = true;
        }
    }
}

int main()
{
    scanf("%d%d", &N, &K);

    printf("%d", f(N));
}
