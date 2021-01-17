from sys import stdin
from collections import deque


def solution():
    h, w = map(int, stdin.readline().split())
    MAP = []
    prisoner = []

    check = [[False] * (w+2) for _ in range(h+2)]
    MAP.append(['.' for _ in range(w+2)])
    for _ in range(h):
        MAP.append(list('.' + stdin.readline().strip() + '.'))
    MAP.append(['.' for _ in range(w+2)])

    for i in range(h+2):
        for j in range(w+2):
            if MAP[i][j] == '$':
                MAP[i][j] = '.'
                prisoner.append([i, j])

    def BFS(MAP, coordinate):
        y, x = coordinate
        result = [[0] * (w+2) for _ in range(h+2)]
        visited = [[False] * (w+2) for _ in range(h+2)]

        dy = [-1, 1, 0, 0]
        dx = [0, 0, -1, 1]
        Q = deque([[y, x]])
        visited[y][x] = True
        check[y][x] = True

        while Q:
            y, x = Q.popleft()
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if 0 <= ny <= h+1 and 0 <= nx <= w+1:
                    if not visited[ny][nx]:
                        visited[ny][nx] = True
                        check[ny][nx] = True
                        if MAP[ny][nx] == '.':
                            Q.appendleft([ny, nx])
                            result[ny][nx] = result[y][x]
                        elif MAP[ny][nx] == '#':
                            Q.append([ny, nx])
                            result[ny][nx] = result[y][x] + 1
        return result

    result = [BFS(MAP, [0, 0]), BFS(MAP, prisoner[0]), BFS(MAP, prisoner[1])]
    result_sum = [[0] * (w+2) for _ in range(h+2)]

    def add_maxtrix(x):
        for i in range(h+2):
            for j in range(w+2):
                result_sum[i][j] += x[i][j]

    list(map(add_maxtrix, result))

    for i in range(h+2):
        for j in range(w+2):
            if MAP[i][j] == '#':
                result_sum[i][j] -= 2
            elif MAP[i][j] == '*' or not check[i][j]:
                result_sum[i][j] = 9876543210

    print(min(map(min, result_sum)))


test_case = int(stdin.readline())
for _ in range(test_case):
    solution()
