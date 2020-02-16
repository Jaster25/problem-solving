#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[100001];
int cnt;
int minSec;

void f(int start)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(start, 0));

    while (!Q.empty())
    {
        pair<int, int> popped = Q.front();
        Q.pop();

        if (popped.first == K)
        {
            if (visited[popped.first] == false)
                minSec = popped.second;
            if (minSec == popped.second)
                cnt++;
            visited[popped.first] = true;
            continue;
        }

        visited[popped.first] = true;
        if (popped.first * 2 <= 100000 && !visited[popped.first * 2])
            Q.push(make_pair(popped.first * 2, popped.second + 1));
        if (popped.first + 1 <= 100000 && !visited[popped.first + 1])
            Q.push(make_pair(popped.first + 1, popped.second + 1));
        if (popped.first - 1 >= 0 && !visited[popped.first - 1])
            Q.push(make_pair(popped.first - 1, popped.second + 1));
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    f(N);
    printf("%d\n%d", minSec, cnt);
}