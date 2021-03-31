from collections import deque
from sys import stdin
import math
import heapq

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

tc = 1
while True:
    N = int(input())
    if not N:
        break

    MAP = [list(map(int, stdin.readline().split())) for _ in range(N)]
    visited = [[float("inf") for _ in range(N)] for _ in range(N)]

    visited[0][0] = MAP[0][0]
    Q = deque([[0, 0]])
    while Q:
        y, x = Q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < N:
                if visited[ny][nx] > visited[y][x] + MAP[ny][nx]:
                    visited[ny][nx] = visited[y][x] + MAP[ny][nx]
                    Q.append([ny, nx])

    print("Problem {0}: {1}".format(tc, visited[N - 1][N - 1]))
    tc += 1
