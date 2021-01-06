from sys import stdin
from collections import deque


def bfs(MAP):
    answer = 0
    N = len(MAP)
    visited = [[False] * N for _ in range(N)]

    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                answer += 1

                # * BFS
                visited[i][j] = True
                Q = deque([[i, j]])
                while Q:
                    y, x = Q.popleft()
                    for d in range(4):
                        ny = y + dy[d]
                        nx = x + dx[d]
                        if 0 <= ny < N and 0 <= nx < N:
                            if not visited[ny][nx] and MAP[ny][nx] == MAP[y][x]:
                                visited[ny][nx] = True
                                Q.append([ny, nx])
    return answer


def solution():
    N = int(stdin.readline())
    MAP1 = []
    for _ in range(N):
        MAP1.append(stdin.readline().strip())
    MAP2 = list(map(lambda x: x.replace('R', 'G'), MAP1))

    print(bfs(MAP1), bfs(MAP2))


solution()
