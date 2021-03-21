from collections import deque
from sys import stdin

T = int(input())

for _ in range(T):
    M, N = map(int, stdin.readline().split())
    MAP = [list(stdin.readline().rstrip()) for _ in range(N)]
    visited = [[0 for _ in range(M)] for _ in range(N)]

    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    # '!': 출구, '.': 빈 공간, '#': 벽, '@': 시작, '*': 불
    is_possible = False
    Q = deque()

    for i in range(N):
        for j in range(M):
            if MAP[i][j] == "*":
                Q.append(["*", i, j])
    for i in range(N):
        for j in range(M):
            if MAP[i][j] == "@":
                Q.append(["@", i, j])
                visited[i][j] = 1

    # find exit
    for x in range(M):
        if MAP[0][x] == ".":
            MAP[0][x] = "!"
        elif MAP[0][x] == "@":
            is_possible = True
    for x in range(M):
        if MAP[N - 1][x] == ".":
            MAP[N - 1][x] = "!"
        elif MAP[N - 1][x] == "@":
            is_possible = True
    for y in range(N):
        if MAP[y][M - 1] == ".":
            MAP[y][M - 1] = "!"
        elif MAP[y][M - 1] == "@":
            is_possible = True
    for y in range(N):
        if MAP[y][0] == ".":
            MAP[y][0] = "!"
        elif MAP[y][0] == "@":
            is_possible = True

    if is_possible:
        print(1)
        continue

    while Q and not is_possible:
        ch, y, x = Q.popleft()

        if ch == "!":
            is_possible = True
            print(visited[y][x])
            break

        if ch == "*":
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if 0 <= ny < N and 0 <= nx < M:
                    if MAP[ny][nx] != "#" and MAP[ny][nx] != "*":
                        Q.append(["*", ny, nx])
                        MAP[ny][nx] = "*"
        else:
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if 0 <= ny < N and 0 <= nx < M:
                    if not visited[ny][nx]:
                        if MAP[ny][nx] == ".":
                            Q.append(["@", ny, nx])
                            visited[ny][nx] = visited[y][x] + 1
                            MAP[ny][nx] = "@"
                        elif MAP[ny][nx] == "!":
                            Q.append(["!", ny, nx])
                            visited[ny][nx] = visited[y][x] + 1
                            MAP[ny][nx] = "@"

    if not is_possible:
        print("IMPOSSIBLE")
