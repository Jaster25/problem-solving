from collections import deque
from sys import stdin


N = int(input())
MAP = [list(map(int, stdin.readline().rstrip())) for _ in range(N)]
visited = [[-1 for _ in range(N)] for _ in range(N)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

Q = deque([[0, 0]])
visited[0][0] = 0

while Q:
    y, x = Q.popleft()
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < N:
            if visited[ny][nx] == -1:
                if MAP[ny][nx] == 0:
                    visited[ny][nx] = visited[y][x] + 1
                    Q.append([ny, nx])
                else:
                    visited[ny][nx] = visited[y][x]
                    Q.appendleft([ny, nx])

print(visited[N - 1][N - 1])
