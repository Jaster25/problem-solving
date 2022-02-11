import sys
from collections import deque
from itertools import permutations

# .: 깨끗한 칸
# *: 더러운 칸
# x: 가구
# o: 로봇 청소기의 시작 위치
def bfs(room, w, h, start, goal):
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]
    is_visited = [[float("inf")] * w for _ in range(h)]
    queue = deque()

    is_visited[start[0]][start[1]] = 0
    queue.append(start)
    while queue:
        y, x = queue.popleft()
        if y == goal[0] and x == goal[1]:
            return is_visited[y][x]

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < h and 0 <= nx < w:
                if room[ny][nx] != "x":
                    if is_visited[ny][nx] > is_visited[y][x] + 1:
                        queue.append([ny, nx])
                        is_visited[ny][nx] = is_visited[y][x] + 1
    return -1


while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == 0 and h == 0:
        break

    room = []
    start = []
    dusts = []
    for i in range(h):
        row = list(sys.stdin.readline().rstrip())
        room.append(row)
        for j in range(w):
            if row[j] == "o":
                start.append(i)
                start.append(j)
            elif row[j] == "*":
                dusts.append([i, j])

    distances = [[0] * len(dusts) for _ in range(len(dusts))]
    for i in range(len(dusts)):
        for j in range(len(dusts)):
            if i == j:  # 같으면 시작점으로부터의 거리
                distance = bfs(room, w, h, [start[0], start[1]], dusts[i])
                distances[i][i] = distance
            else:
                distance = bfs(room, w, h, dusts[i], dusts[j])
                distances[i][j] = distance
                distances[j][i] = distance

    is_possible = True
    for i in range(len(dusts)):
        for j in range(len(dusts)):
            if distances[i][j] == -1:
                is_possible = False

    min_count = float("inf")
    for case in permutations([i for i in range(len(dusts))], len(dusts)):
        sum = distances[case[0]][case[0]]
        for i in range(1, len(dusts)):
            sum += distances[case[i - 1]][case[i]]
        min_count = min(sum, min_count)

    if not is_possible:
        print(-1)
    else:
        print(min_count)
