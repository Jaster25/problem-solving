#include <bits/stdc++.h>
using namespace std;

int N;
int status[21][21];
int sum1, sum2, total;
vector<int> team1;
bool visited[21];
int MIN = 987654321;

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            scanf("%d", &status[i][j]);
            total += status[i][j];
        }
}

void dfs(int cnt, int current)
{
    if (cnt == N / 2)
    {
        sum1 = 0;
        for (int i = 0; i < team1.size(); ++i)
            for (int j = 0; j < team1.size(); ++j)
                sum1 += status[team1[i]][team1[j]];

        bool check[21];
        memset(check, 0, sizeof(check));
        for (int i = 0; i < team1.size(); ++i)
            check[team1[i]] = true;

        vector<int> team2;
        for (int i = 1; i <= N; ++i)
            if (!check[i])
                team2.push_back(i);

        sum2 = 0;
        for (int i = 0; i < team2.size(); ++i)
            for (int j = 0; j < team2.size(); ++j)
                sum2 += status[team2[i]][team2[j]];

        MIN = min(MIN, abs(sum1 - sum2));

        return;
    }

    for (int i = current + 1; i <= N; ++i)
        if (!visited[i])
        {
            visited[i] = true;
            team1.push_back(i);
            dfs(cnt + 1, i);
            visited[i] = false;
            team1.erase(team1.begin() + team1.size() - 1);
        }
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
    {
        visited[i] = true;
        team1.push_back(i);
        dfs(1, i);
        visited[i] = false;
        team1.erase(team1.begin() + team1.size() - 1);
    }
    printf("%d", MIN);
}

int main()
{
    Input();
    Solve();
}
