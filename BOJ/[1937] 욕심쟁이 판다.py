from collections import deque
from sys import stdin
import sys

sys.setrecursionlimit(10 ** 6)

n = int(stdin.readline())
bamboo = [list(map(int, stdin.readline().rstrip().split())) for _ in range(n)]
visited = [[-1] * n for _ in range(n)]

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]


def dfs(y, x):
    if visited[y][x] < 0:
        visited[y][x] = 0
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < n:
                if bamboo[y][x] < bamboo[ny][nx]:
                    visited[y][x] = max(visited[y][x], dfs(ny, nx))
        visited[y][x] += 1
    return visited[y][x]


answer = float("-inf")
for i in range(n):
    for j in range(n):
        answer = max(answer, dfs(i, j))

print(answer)
