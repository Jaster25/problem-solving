from sys import stdin

global answer
answer = 0
cnt = 0

N, M = map(int, stdin.readline().split())
MAP = [list(stdin.readline().strip()) for _ in range(N)]
visited = [[False for _ in range(M)] for _ in range(N)]


def dfs(y, x):
    visited[y][x] = cnt

    nd = MAP[y][x]
    if nd == "U":
        ny = y - 1
        nx = x
    elif nd == "D":
        ny = y + 1
        nx = x
    elif nd == "L":
        ny = y
        nx = x - 1
    elif nd == "R":
        ny = y
        nx = x + 1

    if not visited[ny][nx]:
        dfs(ny, nx)
    elif visited[ny][nx] == cnt:
        global answer
        answer += 1


for i in range(N):
    for j in range(M):
        if not visited[i][j]:
            cnt += 1
            dfs(i, j)

print(answer)