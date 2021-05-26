from sys import stdin
from collections import deque

answer = 0
N, L, R = map(int, stdin.readline().split())
MAP = []

for i in range(N):
    row = list(map(int, stdin.readline().split()))
    MAP.append(row)

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
is_changed = True

while is_changed:
    is_changed = False
    visited = [[False] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                before_border = deque()
                after_border = deque()

                # bfs
                cnt = 1
                total = MAP[i][j]
                visited[i][j] = True
                before_border.append([i, j])

                while before_border:
                    y, x = before_border.popleft()
                    after_border.append([y, x])

                    for d in range(4):
                        ny = y + dy[d]
                        nx = x + dx[d]
                        if 0 <= ny < N and 0 <= nx < N:
                            if not visited[ny][nx]:
                                if L <= abs(MAP[ny][nx] - MAP[y][x]) <= R:
                                    visited[ny][nx] = True
                                    before_border.append([ny, nx])
                                    cnt += 1
                                    total += MAP[ny][nx]

                if cnt > 1:
                    is_changed = True

                per_space = int(total / cnt)

                while after_border:
                    y, x = after_border.popleft()
                    MAP[y][x] = per_space

    answer += 1

print(answer - 1)