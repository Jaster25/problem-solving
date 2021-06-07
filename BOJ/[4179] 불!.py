from sys import stdin, setrecursionlimit
from collections import deque


setrecursionlimit(10 ** 4)

R, C = map(int, stdin.readline().split())
MAP = []
for _ in range(R):
    row = list(stdin.readline().strip())
    MAP.append(row)
visited = [[-1 for _ in range(C)] for _ in range(R)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs():
    queue = deque()
    for i in range(R):
        for j in range(C):
            if MAP[i][j] == "J":
                queue.append(["J", i, j])
                visited[i][j] = 1
            elif MAP[i][j] == "F":
                queue.appendleft(["F", i, j])

    while queue:
        role, y, x = queue.popleft()
        if role == "J":
            if y == 0 or y == R - 1 or x == 0 or x == C - 1:
                queue.clear()
                return visited[y][x]

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < R and 0 <= nx < C and MAP[ny][nx] != "#":
                if role == "F":
                    if MAP[ny][nx] != "F":
                        MAP[ny][nx] = "F"
                        queue.append(["F", ny, nx])
                else:
                    if visited[ny][nx] == -1 and MAP[ny][nx] != "F":
                        visited[ny][nx] = visited[y][x] + 1
                        queue.append(["J", ny, nx])
    return "IMPOSSIBLE"


print(bfs())
