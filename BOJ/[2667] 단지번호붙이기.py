from collections import deque
from sys import stdin


def solution():
    N = int(stdin.readline())
    MAP = [list(map(int, stdin.readline().strip())) for _ in range(N)]
    # N = int(input())
    # MAP = [list(map(int, input())) for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    cnt = 0
    apart = []

    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    def DFS(y, x):
        visited[y][x] = True
        nonlocal cnt
        cnt += 1

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < N:
                if MAP[ny][nx] and not visited[ny][nx]:
                    DFS(ny, nx)

    for i in range(N):
        for j in range(N):
            if MAP[i][j] and not visited[i][j]:
                cnt = 0
                DFS(i, j)
                apart.append(cnt)

    apart.sort()

    print(len(apart))
    for num in apart:
        print(num)


solution()
