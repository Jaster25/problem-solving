from collections import deque
from sys import stdin


def solution():

    N, M = map(int, stdin.readline().split())
    tomato, deq = [], deque()
    visited = [[0 for _ in range(N)] for _ in range(M)]

    for i in range(M):
        row = list(map(int, stdin.readline().split()))
        tomato.append(row)
        for j in range(N):
            if row[j] == 1:
                visited[i][j] = 1
                deq.append([i, j])

    # * BFS
    dy = [1, -1, 0, 0]
    dx = [0, 0, 1, -1]

    while deq:
        y, x = deq.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < M and 0 <= nx < N:
                if tomato[ny][nx] == 0:
                    tomato[ny][nx] = 1
                    visited[ny][nx] = visited[y][x] + 1
                    deq.append([ny, nx])

    # * check
    isAllRipe = True
    for row in tomato:
        if 0 in row:
            isAllRipe = False

    if isAllRipe:
        print(max(map(max, visited)) - 1)
    else:
        print(-1)


solution()
