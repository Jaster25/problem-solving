from collections import deque
from sys import stdin
import sys

sys.setrecursionlimit(10 ** 5)

N, M, K = map(int, stdin.readline().split())
MAP = [list(map(int, list(stdin.readline().rstrip()))) for _ in range(N)]
visited = [[[False] * (K + 1) for _ in range(M)] for _ in range(N)]

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]

# 1: wall, 0: road
# Q: [y, x, k: broken wall, d: date]
Q = deque([[0, 0, 0, 1]])
visited[0][0][0] = True

day = True
is_possible = False
while Q and not is_possible:
    Q_len = len(Q)

    for _ in range(Q_len):
        y, x, k, d = Q.popleft()
        if y == N - 1 and x == M - 1:
            print(d)
            is_possible = True
            break

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if MAP[ny][nx] == 0:
                    if not visited[ny][nx][k]:
                        visited[ny][nx][k] = True
                        Q.append([ny, nx, k, d + 1])
                else:
                    if k + 1 <= K:
                        if day:
                            if not visited[ny][nx][k + 1]:
                                visited[ny][nx][k + 1] = True
                                Q.append([ny, nx, k + 1, d + 1])
                        else:
                            Q.append([y, x, k, d + 1])
    day = not day

if not is_possible:
    print(-1)
