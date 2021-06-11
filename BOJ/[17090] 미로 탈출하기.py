from sys import stdin, setrecursionlimit
from enum import Enum


class Direction(Enum):
    U = 0
    R = 1
    D = 2
    L = 3


setrecursionlimit(10 ** 5 + 300000)

N, M = map(int, stdin.readline().split())
MAP = []
for _ in range(N):
    row = list(stdin.readline().strip())
    MAP.append(row)

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


visited = [[0] * M for _ in range(N)]
# 0: 방문 X
# 1: 탈출 가능
# -1: 진행중 + 탈출 불가능


def dfs(y, x):
    dir = Direction[MAP[y][x]].value
    ny = y + dy[dir]
    nx = x + dx[dir]
    if 0 <= ny < N and 0 <= nx < M:
        if visited[ny][nx] == 0:
            visited[y][x] = -1
            visited[y][x] = dfs(ny, nx)
        else:
            visited[y][x] = visited[ny][nx]
        return visited[y][x]
    return 1


answer = 0
for i in range(N):
    for j in range(M):
        if visited[i][j] == 0:
            visited[i][j] = -1
            visited[i][j] = dfs(i, j)
        if visited[i][j] == 1:
            answer += 1

print(answer)
