#include <bits/stdc++.h>
using namespace std;

int N, edge;
bool isVirus[101];
int answer;
vector<int> computer[101];

void Input()
{
    scanf("%d%d", &N, &edge);
    int a, b;
    for (int i = 0; i < edge; ++i)
    {
        scanf("%d%d", &a, &b);
        computer[a].push_back(b);
        computer[b].push_back(a);
    }
}

void DFS(int n)
{
    for (auto c : computer[n])
        if (!isVirus[c])
        {
            isVirus[c] = true;
            DFS(c);
        }
}

void Solve()
{
    isVirus[1] = true;
    DFS(1);

    for (int i = 2; i <= N; ++i)
        if (isVirus[i])
            answer++;

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
