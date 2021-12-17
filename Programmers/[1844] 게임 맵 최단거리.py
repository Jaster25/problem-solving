from collections import deque


def solution(maps):
    n = len(maps)
    m = len(maps[0])

    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    isVisited = [[-1] * m for _ in range(n)]
    isVisited[0][0] = 0
    queue = deque([[0, 0]])
    while queue:
        y, x = queue.popleft()

        if y == n - 1 and x == m - 1:
            return isVisited[y][x] + 1

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < m:
                if maps[ny][nx] == 1 and isVisited[ny][nx] == -1:
                    isVisited[ny][nx] = isVisited[y][x] + 1
                    queue.append([ny, nx])
    return -1
