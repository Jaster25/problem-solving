from sys import stdin, setrecursionlimit

setrecursionlimit(10 ** 4)


def dfs(y, x):
    dy = [-1, 0, 1, 0, 1, -1, -1, 1]
    dx = [0, 1, 0, -1, 1, -1, 1, -1]
    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < h and 0 <= nx < w:
            if MAP[ny][nx] == 1 and not visited[ny][nx]:
                visited[ny][nx] = True
                dfs(ny, nx)


while True:
    global w, h, MAP
    w, h = map(int, stdin.readline().split())
    if w == 0 and h == 0:
        break

    MAP = []
    islandCount = 0
    visited = [[False] * w for _ in range(h)]

    for i in range(h):
        row = list(map(int, stdin.readline().split()))
        MAP.append(row)

    for i in range(h):
        for j in range(w):
            if MAP[i][j] == 1 and not visited[i][j]:
                visited[i][j] = True
                islandCount += 1
                dfs(i, j)

    print(islandCount)