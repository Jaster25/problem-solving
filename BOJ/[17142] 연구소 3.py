from sys import stdin, setrecursionlimit
from collections import deque
from itertools import combinations
import math

setrecursionlimit(10 ** 4)

# step1: 바이러스 리스트에 담기
# step2: 활성 바이러스 선택 -> combinations
# step3: 선택된 바이러스들로 퍼지는 시간 계산 -> bfs
# step4: step3 비교하여 최소 시간 선별

N, M = map(int, stdin.readline().split(" "))
MAP = []
minSpreadTime = float("inf")

for _ in range(N):
    row = list(map(int, stdin.readline().split(" ")))
    MAP.append(row)

# step1
viruses = []
for i in range(N):
    for j in range(N):
        if MAP[i][j] == 2:
            viruses.append([i, j])


def bfs(activeViruses):
    global N, MAP
    visited = [[-1 for _ in range(N)] for _ in range(N)]
    queue = deque()

    for activeVirus in activeViruses:
        queue.append(activeVirus)
        visited[activeVirus[0]][activeVirus[1]] = 0

    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < N and 0 <= nx < N:
                if visited[ny][nx] == -1:
                    if MAP[ny][nx] == 0:
                        visited[ny][nx] = visited[y][x] + 1
                        queue.append([ny, nx])
                    #! 비활성 바이러스
                    elif MAP[ny][nx] == 2:
                        visited[ny][nx] = visited[y][x] + 1
                        queue.append([ny, nx])

    maxTime = 0
    for i in range(N):
        for j in range(N):
            if MAP[i][j] == 0:
                if visited[i][j] == -1:
                    return -1
                else:
                    maxTime = max(maxTime, visited[i][j])
    return maxTime


# step2
for activeViruses in combinations(viruses, M):
    # step3
    spreadTime = bfs(activeViruses)
    # 퍼뜨린다면
    if spreadTime != -1:
        # step4
        minSpreadTime = min(spreadTime, minSpreadTime)

if math.isinf(minSpreadTime):
    print(-1)
else:
    print(minSpreadTime)
