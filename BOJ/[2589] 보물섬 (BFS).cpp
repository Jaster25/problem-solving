#include <bits/stdc++.h>
using namespace std;

int a, b;
char island[51][51];
int visited[51][51];
queue<pair<int, int>> Q;

void reset()
{
  for (int i = 0; i < a; ++i)
    for (int j = 0; j < b; ++j)
      if (island[i][j] == 'L')
        visited[i][j] = -1;
      else
        visited[i][j] = -2;
}

void bfs(int startY, int startX)
{
  Q.push({startY, startX});
  visited[startY][startX] = 0;

  int dirY[4] = {1, -1, 0, 0};
  int dirX[4] = {0, 0, 1, -1};

  while (!Q.empty())
  {
    int y = Q.front().first;
    int x = Q.front().second;
    Q.pop();

    for (int i = 0; i < 4; ++i)
    {
      int nextY = y + dirY[i];
      int nextX = x + dirX[i];
      if (nextY >= 0 && nextY < a && nextX >= 0 && nextX < b)
      {
        if (visited[nextY][nextX] == -1)
        {
          Q.push({nextY, nextX});
          visited[nextY][nextX] = visited[y][x] + 1;
        }
      }
    }
  }
}

int findMax()
{
  int max = 0;
  for (int i = 0; i < a; ++i)
    for (int j = 0; j < b; ++j)
      if (max < visited[i][j])
        max = visited[i][j];
  return max;
}

int main()
{
  scanf("%d%d", &a, &b);
  getchar();

  for (int i = 0; i < a; ++i)
  {
    for (int j = 0; j < b; ++j)
      scanf("%c", &island[i][j]);
    getchar();
  }

  int maxTime = 0;
  for (int i = 0; i < a; ++i)
  {
    for (int j = 0; j < b; ++j)
    {
      if (island[i][j] == 'L')
      {
        reset();
        bfs(i, j);

        if (maxTime < findMax())
          maxTime = findMax();
      }
    }
  }

  printf("%d", maxTime);
}
