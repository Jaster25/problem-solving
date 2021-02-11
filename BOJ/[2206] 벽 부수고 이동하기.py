from sys import stdin
from collections import deque


def solution():
    MAP = []
    N, M = list(map(int, stdin.readline().strip().split()))
    for _ in range(N):
        MAP.append(list(map(int, stdin.readline().strip())))

    # 0,0 => N-1, M-1
    # 0: road, 1: wall
    visited = [[[0] * 2 for i in range(M)] for j in range(N)]

    # [][][0] => Not yet broken
    dy, dx = [-1, 0, 1, 0], [0, 1, 0, -1]

    q = deque()
    q.append([0, 0, 0])
    visited[0][0][0] = 1

    while q:
        y, x, isBroken = q.popleft()
        if y == N - 1 and x == M - 1:
            return visited[y][x][isBroken]

        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if MAP[ny][nx] == 0 and visited[ny][nx][isBroken] == 0:
                    visited[ny][nx][isBroken] = visited[y][x][isBroken] + 1
                    q.append([ny, nx, isBroken])
                # Break wall
                elif MAP[ny][nx] == 1 and isBroken == 0:
                    visited[ny][nx][1] = visited[y][x][0] + 1
                    q.append([ny, nx, 1])
    return -1


print(solution())