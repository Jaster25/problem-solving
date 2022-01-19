import sys

sys.setrecursionlimit(1000000)


# DP 3차원 방향까지
is_visited = [[[0] * 4 for _ in range(501)] for _ in range(501)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def change_direction(current, ch):
    if ch == "S":
        return current
    elif ch == "L":
        return (current + 3) % 4
    else:
        return (current + 1) % 4


def dfs(grid, y, x, d, count):
    is_visited[y][x][d] = count

    nd = change_direction(d, grid[y][x])
    ny = y + dy[nd]
    nx = x + dx[nd]

    if ny >= len(grid):
        ny = 0
    elif nx >= len(grid[0]):
        nx = 0
    elif ny < 0:
        ny = len(grid) - 1
    elif nx < 0:
        nx = len(grid[0]) - 1

    if is_visited[ny][nx][nd]:
        return count
    else:
        return dfs(grid, ny, nx, nd, count + 1)


def solution(grid):
    answer = []
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            for d in range(4):
                if not is_visited[i][j][d]:
                    answer.append(dfs(grid, i, j, d, 1))
    answer.sort()
    return answer
