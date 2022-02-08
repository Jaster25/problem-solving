import sys
from collections import deque

# (1 ≤ W, H ≤ 100)
W, H = map(int, sys.stdin.readline().split())

# .: 빈 칸
# *: 벽
# C: 레이저로 연결해야 하는 칸
MAP = []
targets = []
for i in range(H):
    row = list(sys.stdin.readline().rstrip())
    MAP.append(row)
    for j in range(W):
        if row[j] == "C":
            targets.append([i, j])


dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs(y, x):
    is_visited = [[float("inf")] * W for _ in range(H)]

    queue = deque([[y, x]])
    is_visited[y][x] = -1
    while queue:
        y, x = queue.popleft()
        if y == targets[1][0] and x == targets[1][1]:
            return is_visited[y][x]

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            while True:
                if not (0 <= ny < H and 0 <= nx < W):
                    break
                if MAP[ny][nx] == "*":
                    break
                if is_visited[ny][nx] < is_visited[y][x] + 1:
                    break
                queue.append([ny, nx])
                is_visited[ny][nx] = is_visited[y][x] + 1
                ny += dy[i]
                nx += dx[i]


print(bfs(targets[0][0], targets[0][1]))
