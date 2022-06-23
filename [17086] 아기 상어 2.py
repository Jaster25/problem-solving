import sys
from collections import deque


N, M = map(int, sys.stdin.readline().split())

MAP = []
queue = deque()
for y in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    MAP.append(row)
    for x in range(M):
        if row[x] == 1:
            queue.append([y, x])

# 8방향(대각선 포함)
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

while queue:
    y, x = queue.popleft()
    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            if MAP[ny][nx] == 0:
                MAP[ny][nx] = MAP[y][x] + 1
                queue.append([ny, nx])

max_safe_distance = 0
for y in range(N):
    for x in range(M):
        max_safe_distance = max(MAP[y][x], max_safe_distance)

print(max_safe_distance - 1)
