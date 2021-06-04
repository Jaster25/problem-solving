from sys import stdin
from collections import deque

N, M = map(int, stdin.readline().split(" "))

bulbSwitch = [[[] for _ in range(N + 1)] for _ in range(N + 1)]
visited = [[False for _ in range(N + 1)] for _ in range(N + 1)]
brighted = [[False for _ in range(N + 1)] for _ in range(N + 1)]

for i in range(M):
    x, y, a, b = map(int, stdin.readline().split(" "))
    bulbSwitch[y][x].append([b, a])

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

queue = deque()
queue.append([1, 1])
visited[1][1] = True
brighted[1][1] = True
brightRoomCnt = 1

while queue:
    y, x = queue.popleft()
    for by, bx in bulbSwitch[y][x]:
        if not brighted[by][bx]:
            brighted[by][bx] = True
            brightRoomCnt += 1

            # 역으로 확인하기
            for i in range(4):
                nby = by + dy[i]
                nbx = bx + dx[i]
                if 1 <= nby <= N and 1 <= nbx <= N:
                    if visited[nby][nbx]:
                        queue.append([nby, nbx])

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 1 <= ny <= N and 1 <= nx <= N:
            if not visited[ny][nx] and brighted[ny][nx]:
                queue.append([ny, nx])
                visited[ny][nx] = True


print(brightRoomCnt)
