import sys
from collections import deque

N, M, K = map(int, sys.stdin.readline().split())
is_food = [[False] * M for _ in range(N)]
is_visited = [[False] * M for _ in range(N)]
for _ in range(K):
    y, x = map(int, sys.stdin.readline().split())
    is_food[y - 1][x - 1] = True

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs(start_y, start_x):
    queue = deque()
    count = 1
    queue.append([start_y, start_x])
    is_visited[start_y][start_x] = True
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if is_food[ny][nx]:
                    if not is_visited[ny][nx]:
                        count += 1
                        queue.append([ny, nx])
                        is_visited[ny][nx] = True
    return count


max_food_size = 0
for y in range(N):
    for x in range(M):
        if is_food[y][x] and not is_visited[y][x]:
            food_size = bfs(y, x)
            max_food_size = max(food_size, max_food_size)

print(max_food_size)
