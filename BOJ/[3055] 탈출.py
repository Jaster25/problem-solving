from sys import stdin
from collections import deque

# S: hedgehog, D: goal, *: water, .: empty, X: stone
R, C = map(int, stdin.readline().split())
MAP = [list(stdin.readline().rstrip()) for _ in range(R)]
visited = [[0 for _ in range(C)] for _ in range(R)]
hedgehog_y, hedgehog_x = [[i, j] for i in range(R) for j in range(C) if MAP[i][j] == "S"][0]

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def flood():
    flood_Q = deque([[i, j] for i in range(R) for j in range(C) if MAP[i][j] == "*"])
    while flood_Q:
        y, x = flood_Q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < R and 0 <= nx < C:
                if MAP[ny][nx] == ".":
                    MAP[ny][nx] = "*"


step = 0
isDone = False
Q = deque([[hedgehog_y, hedgehog_x]])
visited[hedgehog_y][hedgehog_x] = 1

while Q:
    y, x = Q.popleft()

    if MAP[y][x] == "D":
        print(visited[y][x] - 1)
        isDone = True
        break

    if visited[y][x] > step:
        flood()
        step += 1

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < R and 0 <= nx < C:
            if MAP[ny][nx] == "." or MAP[ny][nx] == "D":
                if not visited[ny][nx]:
                    visited[ny][nx] = visited[y][x] + 1
                    Q.append([ny, nx])

if not isDone:
    print("KAKTUS")
