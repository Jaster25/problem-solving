import sys
from collections import deque

# 2 <= N <= 50
N = int(sys.stdin.readline())

# ‘#’는 문이 설치된 곳으로 항상 두 곳이며,
# ‘.’은 아무 것도 없는 것으로 빛은 이 곳을 통과한다.
# ‘!’은 거울을 설치할 수 있는 위치를 나타내고,
# ‘*’은 빛이 통과할 수 없는 벽을 나타낸다.
doors = []
house = []
for y in range(N):
    row = sys.stdin.readline()
    house.append(row)
    for x in range(N):
        if house[y][x] == "#":
            doors.append([y, x])

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

is_visited = [[[-1] * 4 for _ in range(N + 1)] for _ in range(N + 1)]

queue = deque()
for i in range(4):
    ny = doors[0][0] + dy[i]
    nx = doors[0][1] + dx[i]
    if 0 <= ny < N and 0 <= nx < N:
        if house[ny][nx] != "*":
            queue.append([ny, nx, i])
            is_visited[ny][nx][i] = 0

while queue:
    y, x, d = queue.popleft()
    if y == doors[1][0] and x == doors[1][1]:
        continue

    # 여기는 직진만
    ny = y + dy[d]
    nx = x + dx[d]
    if 0 <= ny < N and 0 <= nx < N:
        if house[ny][nx] != "*":
            if is_visited[ny][nx][d] == -1 or is_visited[ny][nx][d] > is_visited[y][x][d]:
                is_visited[ny][nx][d] = is_visited[y][x][d]
                queue.append([ny, nx, d])

    # 해당 위치에 거울 설치
    if house[y][x] == "!":
        nd = (d + 1) % 4
        ny = y + dy[nd]
        nx = x + dx[nd]
        if 0 <= ny < N and 0 <= nx < N:
            if house[ny][nx] != "*":
                if is_visited[ny][nx][nd] == -1 or is_visited[ny][nx][nd] > is_visited[y][x][d] + 1:
                    is_visited[ny][nx][nd] = is_visited[y][x][d] + 1
                    queue.append([ny, nx, nd])

        nd = (d + 3) % 4
        ny = y + dy[nd]
        nx = x + dx[nd]
        if 0 <= ny < N and 0 <= nx < N:
            if house[ny][nx] != "*":
                if is_visited[ny][nx][nd] == -1 or is_visited[ny][nx][nd] > is_visited[y][x][d] + 1:
                    is_visited[ny][nx][nd] = is_visited[y][x][d] + 1
                    queue.append([ny, nx, nd])

answer = []
for count in is_visited[doors[1][0]][doors[1][1]]:
    if count != -1:
        answer.append(count)
print(min(answer))
