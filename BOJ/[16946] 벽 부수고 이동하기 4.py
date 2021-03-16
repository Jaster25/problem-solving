from collections import deque
import sys

sys.setrecursionlimit(10 ** 5 + 333000)

# 0: empty, 1: wall
N, M = map(int, sys.stdin.readline().split())
MAP = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(N)]
visited = [[0 for _ in range(M)] for _ in range(N)]
answer = [i[:] for i in MAP]

for i in range(N):
    for j in range(M):
        if MAP[i][j] == 1:
            visited[i][j] = -1

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

global label
label = deque()


def dfs(y, x):
    global label
    label[len(label) - 1] = label[len(label) - 1] + 1

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < M:
            if MAP[ny][nx] == 0 and not visited[ny][nx]:
                visited[ny][nx] = visited[y][x]
                dfs(ny, nx)


for i in range(N):
    for j in range(M):
        if MAP[i][j] == 0 and not visited[i][j]:
            label.append(0)
            visited[i][j] = len(label)
            dfs(i, j)

for i in range(N):
    for j in range(M):
        if MAP[i][j] == 1:
            answer[i][j] = 1
            used = set()
            for k in range(4):
                ny = i + dy[k]
                nx = j + dx[k]
                if 0 <= ny < N and 0 <= nx < M:
                    if visited[ny][nx] != -1 and (visited[ny][nx] - 1) not in used:
                        answer[i][j] = (answer[i][j] + label[visited[ny][nx] - 1]) % 10
                        used.add(visited[ny][nx] - 1)

for i in answer:
    for j in i:
        print(j, end="")
    print("")
