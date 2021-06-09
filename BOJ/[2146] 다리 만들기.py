from sys import stdin, setrecursionlimit
from collections import deque

setrecursionlimit(10 ** 4)

N = int(stdin.readline())
visited = [[-1 for _ in range(N)] for _ in range(N)]
hostOfArea = [[0 for _ in range(N)] for _ in range(N)]
islandCount = 0
MAP = []
for _ in range(N):
    row = list(map(int, stdin.readline().split()))
    MAP.append(row)

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

queue = deque()

# 섬의 테두리부터 시작해야 처리하기 수월
def findEdgeOfIsland(y, x):
    isAppended = False
    visited[y][x] = 0
    hostOfArea[y][x] = islandCount
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < N:
            if visited[ny][nx] == -1:
                if MAP[ny][nx] == 0:
                    if not isAppended:
                        queue.append([y, x])
                        isAppended = True
                else:
                    findEdgeOfIsland(ny, nx)


for i in range(N):
    for j in range(N):
        if MAP[i][j] == 1 and visited[i][j] == -1:
            islandCount += 1
            hostOfArea[i][j] = islandCount
            findEdgeOfIsland(i, j)

curStep = 0
answer = []
while queue:
    y, x = queue.popleft()

    if visited[y][x] != curStep:
        curStep = visited[y][x]
        if answer:
            queue.clear()
            break

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < N and 0 <= nx < N:
            if visited[ny][nx] != -1:
                if hostOfArea[ny][nx] != hostOfArea[y][x]:
                    answer.append(visited[ny][nx] + visited[y][x])
                    break
            else:
                visited[ny][nx] = visited[y][x] + 1
                hostOfArea[ny][nx] = hostOfArea[y][x]
                queue.append([ny, nx])


print(min(answer))