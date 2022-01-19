import sys
from collections import deque

# 빙판이 언제 녹는지 queue에 기록
# 이분 탐색 & BFS로 필요한 최소 날짜 확인
R, C = map(int, sys.stdin.readline().split())
lake = []
swans = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

water_queue = deque()
melted_date = [[0] * C for _ in range(R)]
for i in range(R):
    row = list(sys.stdin.readline().rstrip())
    lake.append(row)
    for j in range(C):
        if lake[i][j] == "L":
            swans.append([i, j])
        if lake[i][j] != "X":
            water_queue.append([i, j])


def can_meet(date):
    is_visited = [[False] * C for _ in range(R)]
    queue = deque([[swans[0][0], swans[0][1]]])

    is_visited[swans[0][0]][swans[0][1]] = True
    while queue:
        y, x = queue.popleft()
        if y == swans[1][0] and x == swans[1][1]:
            return True

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < R and 0 <= nx < C:
                if melted_date[ny][nx] <= date:
                    if not is_visited[ny][nx]:
                        is_visited[ny][nx] = True
                        queue.append([ny, nx])
    return False


date = 1
while water_queue:
    term = len(water_queue)
    melting = []

    for _ in range(term):
        y, x = water_queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < R and 0 <= nx < C:
                if lake[ny][nx] == "X" and melted_date[ny][nx] == 0:
                    melting.append([ny, nx])

    for y, x in melting:
        if melted_date[y][x] > 0:
            continue
        melted_date[y][x] = date
        water_queue.append([y, x])
    date += 1


left = 0
right = date
answer = right
while left <= right:
    mid = (left + right) // 2
    if can_meet(mid):
        answer = mid
        right = mid - 1
    else:
        left = mid + 1
print(answer)
