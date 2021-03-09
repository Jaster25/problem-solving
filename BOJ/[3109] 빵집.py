from sys import stdin


max_cnt = 0
R, C = map(int, stdin.readline().split())
MAP = [list(stdin.readline().strip()) for _ in range(R)]
visited = [[False] * C for _ in range(R)]

dy = [-1, 0, 1]
dx = [1, 1, 1]


def connect_pipe(y, x):
    if x == C - 1:
        return True
    for i in range(3):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < R and 0 <= nx < C:
            if not visited[ny][nx]:
                visited[ny][nx] = True
                if MAP[ny][nx] == ".":
                    if connect_pipe(ny, nx):
                        return True
    return False


for i in range(R):
    if MAP[i][0] == ".":
        if connect_pipe(i, 0):
            max_cnt += 1

print(max_cnt)
