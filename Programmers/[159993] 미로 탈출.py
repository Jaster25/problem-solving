from collections import deque

"""
BFS 1차: 시작 지점 -> 레버
BFS 2차: 레버 -> 출구
"""

def solution(maps):
    start_y, start_x = find_position(maps, "S")
    lever_y, lever_x = find_position(maps, "L")
    goal_y, goal_x = find_position(maps, "E")

    cnt1 = bfs(maps, start_y, start_x, lever_y, lever_x)
    cnt2 = bfs(maps, lever_y, lever_x, goal_y, goal_x)

    if cnt1 == -1 or cnt2 == -1:
      return -1
    return cnt1 + cnt2


def find_position(maps, target):
    for i in range(len(maps)):
        for l in range(len(maps[0])):
            if maps[i][l] == target:
                return i, l


def bfs(maps, start_y, start_x, goal_y, goal_x):
    n = len(maps)
    m = len(maps[0])
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    is_visited = [[-1] * m for _ in range(n)]
    is_visited[start_y][start_x] = 0

    queue = deque([[start_y, start_x]])
    while queue:
        y, x = queue.popleft()

        if y == goal_y and x == goal_x:
            return is_visited[y][x]

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < m:
                if not maps[ny][nx] == "X" and is_visited[ny][nx] == -1:
                    is_visited[ny][nx] = is_visited[y][x] + 1
                    queue.append([ny, nx])

    # 탈출할 수 없는 경우
    return -1


if __name__ == "__main__":
    maps = 	["LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"]
    print(solution(maps))