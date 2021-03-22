from collections import deque
from sys import stdin

N, M, K = map(int, stdin.readline().split())
MAP = [list(map(int, list(stdin.readline().rstrip()))) for _ in range(N)]
visited = [[[0] * (K + 1) for _ in range(M)] for _ in range(N)]

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]

# Q[k, y, x]
# 1: wall, 0: road
Q = deque([[0, 0, 0]])
visited[0][0][0] = 1

while Q:
    y, x, k = Q.popleft()

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            if MAP[ny][nx] == 0:
                if not visited[ny][nx][k] or visited[ny][nx][k] > visited[y][x][k] + 1:
                    visited[ny][nx][k] = visited[y][x][k] + 1
                    Q.append([ny, nx, k])
            elif k + 1 <= K:
                if not visited[ny][nx][k + 1] or visited[ny][nx][k + 1] > visited[y][x][k] + 1:
                    visited[ny][nx][k + 1] = visited[y][x][k] + 1
                    Q.append([ny, nx, k + 1])

goal = list(cnt for cnt in visited[N - 1][M - 1] if cnt != 0)
print(min(goal) if not goal == [] else -1)
