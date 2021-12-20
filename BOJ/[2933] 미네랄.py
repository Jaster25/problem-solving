import sys
from collections import deque


R, C = map(int, sys.stdin.readline().split())

cave = []
for i in range(R):
    row = sys.stdin.readline().rstrip()
    cave.append(list(row))

N = int(sys.stdin.readline())
height = list(map(int, sys.stdin.readline().split()))

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def break_mineral(turn, height):
    # 왼->오
    if turn == 0:
        for i in range(C):
            if cave[height][i] == "x":
                cave[height][i] = "."
                return i
    # 오->왼
    else:
        for i in range(C - 1, -1, -1):
            if cave[height][i] == "x":
                cave[height][i] = "."
                return i
    return -1


def is_floating(startY, startX):
    if startY == R:
        return False

    is_visited = [[False] * C for _ in range(R)]
    is_visited[startY][startX] = True
    queue = deque([[startY, startX]])
    while queue:
        y, x = queue.pop()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny == R:
                return False

            if 0 <= ny < R and 0 <= nx < C:
                if cave[ny][nx] == "x" and not is_visited[ny][nx]:
                    is_visited[ny][nx] = True
                    queue.append([ny, nx])
    return True


def go_down(startY, startX):
    # 클러스터 좌표 담기
    cluster = [[startY, startX]]
    # BFS
    cave[startY][startX] = "."
    queue = deque([[startY, startX]])
    is_visited = [[False] * C for _ in range(R)]
    is_visited[startY][startX] = True
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < R and 0 <= nx < C:
                if cave[ny][nx] == "x" and not is_visited[ny][nx]:
                    cluster.append([ny, nx])
                    cave[ny][nx] = "."
                    queue.append([ny, nx])
                    is_visited[ny][nx] = True

    # 최대한 내려갈 수 있는 곳 탐색
    index = 0
    is_lowest = False
    while not is_lowest:
        for y, x in cluster:
            ny = y + index
            if ny == R or cave[ny][x] == "x":
                is_lowest = True
                break
        else:
            index += 1
    index -= 1

    # 내리기
    for y, x in cluster:
        ny = y + index
        cave[ny][x] = "x"


def print_cave():
    for row in cave:
        print("".join(row))


# turn 0: 왼->오, 1: 오->왼
turn = 0
for h in height:
    broken_y = R - h
    broken_x = break_mineral(turn, broken_y)
    turn = (turn + 1) % 2

    # 파괴된 미네랄이 없는 경우
    if broken_x == -1:
        continue

    connected_broken_mineral = []
    for i in range(4):
        ny = broken_y + dy[i]
        nx = broken_x + dx[i]
        if 0 <= ny < R and 0 <= nx < C:
            if cave[ny][nx] == "x":
                connected_broken_mineral.append([ny, nx])

    for y, x in connected_broken_mineral:
        if is_floating(y, x):
            go_down(y, x)
            break

print_cave()
